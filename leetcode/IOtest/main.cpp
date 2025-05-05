#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



TreeNode * createTree(vector<string> str)
{
    if(str.size() == 0 || str[0] == "null") return nullptr;
    TreeNode *root = new TreeNode(stoi(str[0]));
    /*创建一个队列：先入先出*/
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (i < str.size())
    {
        //取出队列中的当前节点
        TreeNode *curr = q.front();
        q.pop();

        if (str[i] != "null" && i < str.size())
        {
            TreeNode *node = new TreeNode(stoi(str[i]));
            curr->left = node;
            q.push(curr->left);
        }

        i++;
        if (str[i] != "null" && i < str.size())
        {
            TreeNode *node = new TreeNode(stoi(str[i]));
            curr->right = node;
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main()
{
    string s, word;
    vector<string> str;
    getline(cin, s);
    stringstream ss(s);
    while(ss>>word)
    {
        str.push_back(word);
    }
    TreeNode *root = createTree(str);
    cout<< "finsh" <<endl;


    return 0;
}