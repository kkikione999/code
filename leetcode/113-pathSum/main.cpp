#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 构造二叉树（层序）辅助函数
TreeNode* buildTree(const vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

// 你之前的函数放这
vector<vector<int>> result;
vector<int> path;

void dfs(TreeNode* root, int currentSum, int targetSum) {
    if (root == nullptr) return;
    path.push_back(root->val);
    currentSum += root->val;
    if (currentSum == targetSum && root->left == nullptr && root->right == nullptr) {
        path.pop_back();
        result.push_back(vector<int>(path));
        return;
    }
    dfs(root->left, currentSum, targetSum);
    dfs(root->right, currentSum, targetSum);
    path.pop_back();
}

void dfss(TreeNode* root, int currentSum, int targetSum) {
    if (root == nullptr) return;
    path.push_back(root->val);
    currentSum += root->val;
    if(root->left == nullptr && root->right == nullptr){
        if(currentSum == targetSum){
            result.push_back(path);
        }
        path.pop_back();
        return;
    }
    dfss(root->left, currentSum, targetSum);
    dfss(root->right, currentSum, targetSum);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    result.clear();
    path.clear();
    dfs(root, 0, targetSum);
    return result;
}


/*
void dfs (TreeNode* root, int targetSum) {
  int tempSum = 0;
  if(root == nullptr) return;
  path.push_back(root->val);
  for (int i = 0; i < path.size(); i++) {
    tempSum += path[i];
  }
  if (tempSum >= targetSum) {
    if(tempSum == targetSum) {
      if(root->left == nullptr && root->right == nullptr) {
        result.push_back(path);
      }
    }
    path.pop_back();
    return ;
  }
  dfs(root->left,targetSum);
  dfs(root->right,targetSum);
  path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

  dfs(root,targetSum);
  return result;

}
*/

int main() {
    vector<int> vals = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};  // 用 -1 表示 null
    int target = 22;
    TreeNode* root = buildTree(vals);

    vector<vector<int>> paths = pathSum(root, target);
    for (auto& p : paths) {
        for (int x : p) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
