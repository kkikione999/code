#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data): val(data), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(vector<string>& nums)
{
    if (nums.size() == 0 || nums[0] == "null")   return nullptr;
    TreeNode* root = new TreeNode(stoi(nums[0]));

    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size())
    {
        TreeNode* curr = q.front();
        //记得出栈
        q.pop();
        if (nums[i] != "null" && i < nums.size())
        {
            TreeNode* node = new TreeNode(stoi(nums[i]));
            curr->left = node;
            q.push(node);
        }
        i++;
        if (nums[i] != "null" && i < nums.size())
        {
            TreeNode* node = new TreeNode(stoi(nums[i]));
            curr->right = node;
            q.push(node);
        }
        i++;
    }
    return root;
}


// class Solution {
// public:
// #define max( a, b ) ((a) > (b) ? (a): (b))
//     int rob(TreeNode* root) {
//         vector<int> nums = robTree(root);
//         return max(nums[0], nums[1]);
//
//     }
//     //返回值： 0：不偷     1：偷
//     vector<int> robTree(TreeNode* root)
//     {
//         if (root == nullptr) return vector<int>{0,0};
//         vector<int> left = robTree(root->left);
//         vector<int> right = robTree(root->right);
//         //不偷当前节点
//         int val0 = max(left[0], left[1]) + max(right[0], right[1]);
//         //偷当前节点
//         int val1 = left[0] + right[0] + root->val;
//
//         //返回值第一个是不偷当前节点的 对应的
//         return {val0, val1};
//     }
// };
class Solution {
public:
#define max( a, b ) ((a) > (b) ? (a): (b))
    int rob(TreeNode* root) {
        vector<int> val = robTree(root);
        return max( val[0], val[1] );
    }
    //返回值： 0：不偷     1：偷
    //就用两个值记录当前节点偷和不偷的最大值
    //如果偷当前节点：那么就是不偷子节点的最大值+当前节点的最大值
    //如果不偷当前节点：那么就是偷两个子节点的最大值+当前节点的最大值
    vector<int> robTree(TreeNode* root)
    {
        if (root == nullptr) return vector<int>{0,0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        //不偷当前节点
        int val0 = max(left[0], left[1]) + max(right[0], right[1]);
        //偷当前节点
        int val1 = left[0] + right[0] + root->val;
        return {val0, val1};

    }
};


int main()
{
    string word, s;
    vector<string> nums;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> word)
    {
        nums.push_back(word);
    }
    TreeNode* root = createTree(nums);
    Solution test;
    cout << test.rob(root) << endl;

    return 0;
}