#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isPathSum;

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        recursive_tree(root, sum, targetSum);
        return isPathSum;

    }

    void recursive_tree(TreeNode* node, int sum, int targetSum)
    {
        if (node == nullptr) return ;
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum == targetSum)
                isPathSum = true;
            return ;
        }

        recursive_tree(node->left, sum, targetSum);
        recursive_tree(node->right, sum, targetSum);

    }
};


TreeNode* buildTree(vector<string> s)
{
    if (s.empty() || s[0] == "null")
        return nullptr;
    TreeNode* root = new TreeNode(stoi(s[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i<s.size())
    {
        TreeNode* curr = q.front();
        q.pop();
        if (s[i] != "null" && i<s.size())
        {
            curr->left = new TreeNode(stoi(s[i]));
            q.push(curr->left);
        }
        i++;
        if (s[i] != "null" && i<s.size())
        {
            curr->right = new TreeNode(stoi(s[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main()
{
    //vector<string> strings = {"5","4","8","11","null","13","4","7","2","null","null","null","1"};
    //vector<string> strings = {"1","2", "3"};
    vector<string> strings;
    int targetsum = 0;


    string st;
    getline(cin , st);
    cin >> targetsum;
    stringstream ss(st);
    string word;
    while (ss>>word)
    {
        strings.push_back(word);
    }





    Solution s;
    TreeNode * tree = buildTree(strings);
    bool a = s.hasPathSum(tree, 22);
    cout << a << endl;
    return 0;
}