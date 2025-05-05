#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

//1 red    2 green   3 blue
//
using namespace std;
// #define color_change(curr, times) curr = (times + curr)%3
// 1 3

int SWITCH;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int data){val = data; left = nullptr; right = nullptr;}
};

TreeNode * createTree(vector<int> *init)
{

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode (init->at(0));
    q.push(root);
    int i = 1;
    while (i<init->size())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (init->at(i) != 0 && i<init->size())
        {
            TreeNode *node = new TreeNode(init->at(i));
            curr->left = node;
            q.push(node);
        }
        i++;
        if (i<init->size() && init->at(i) != 0)
        {
            TreeNode *node = new TreeNode(init->at(i));
            curr->right = node;
            q.push(node);
        }
        i++;
    }
    return root;
}

int biao[] = {0,1,2,3,1,2};
int switch_times(int it1, int it2)
{
    int i = it1;
    while (it2 != biao[i])
    {
        i++;
    }
    return i-it1;
}

int switch2(int it1 , int nums)
{
    int i = it1;
    return biao[it1 + nums];
}


//
// 15
// 1 2 3 1 2 3 3 2 1 1 2 1 0 3 1
// 1 2 3 1 2 3 3 2 1 1 2 1 0 2 2

void sub_func(TreeNode *root, TreeNode *tar_root, int switchs)
{
    if (root == nullptr) return;
    int it1 = switch2(root->val, switchs);
    int it2 = tar_root->val;
    if (it1 != it2)
    {

        int temp = switch_times(it1, it2);
        SWITCH += temp;
        switchs += temp;
    }
    sub_func(root->left, tar_root->left, switchs);
    sub_func(root->right, tar_root->right, switchs);
}

int switch_min (TreeNode *init, TreeNode *tar)
{
    sub_func(init, tar, 0);
    return SWITCH;
}

int main()
{
    int num;
    cin>>num;
    vector<int> initial(num);
    vector<int> target(num);

    for(int i=0;i<num;i++)
    {
        cin>>initial[i];
    }
    for(int i=0;i<num;i++)
    {
        cin>>target[i];
    }
    if (initial[0] == 0 || target[0] == 0) return 0;

    TreeNode* init = createTree(&initial);
    TreeNode* tag = createTree(&target);
    switch_min(init, tag);
    cout << SWITCH << endl;
    return 0;
}