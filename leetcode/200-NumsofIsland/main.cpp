#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
  if (visited[x][y] || grid[x][y] == 0) return; // 终止条件：访问过的节点 或者 遇到海水
  visited[x][y] = true; // 标记访问过
  for (int i = 0; i < 4; i++) {
    int nextx = x + dir[i][0];
    int nexty = y + dir[i][1];
    if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 越界了，直接跳过
    dfs(grid, visited, nextx, nexty);
  }
}


int main(){
  int n;


}