#include <iostream>
#include <queue>
#include <vector>
#include <sstream>


using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode * createTree(vector <string> str) {
  if(str.size() == 0) return nullptr;
  if (str[0] == "null") return nullptr;
  TreeNode *root = new TreeNode(stoi(str[0]));
  queue<TreeNode*> q;
  q.push(root);
  for(int i = 1; i < str.size(); i++)
  {
    TreeNode * curr = q.front();
    q.pop();
    if(str[i] == "null" && i < str.size() )
    {
      TreeNode * newNode = new TreeNode(stoi(str[i]));
      curr->left = newNode;
      q.push(curr->left);
    }
    i++;
    if(str[i] == "null" && i < str.size() )
    {
      TreeNode * newNode = new TreeNode(stoi(str[i]));
      curr->right = newNode;
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

int main(){
  string str,temp;
  getline(cin, str);
  stringstream ss(str);
  vector<string> v;
  while(ss>>temp)
  {
    v.push_back(temp);
  }
  for(auto it : v)
  {
    cout << it << endl;
  }

  return 0;
}