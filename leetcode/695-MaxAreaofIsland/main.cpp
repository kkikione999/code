#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
	int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	#define max(a, b) ((a) > (b) ? (a) : (b))
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		int max_area = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1 && !visited[i][j]) {
					int temp = bfs(grid, visited, i, j);
					max_area = max(max_area, temp);
				}
			}
		}
		return max_area;

	}

	int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
		queue<pair<int, int>> que;
		que.emplace(x, y);
		visited[x][y] = true;
		int area = 1;
		while (!que.empty()) {
			pair<int, int> p = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int tx = p.first + dir[i][0];
				int ty = p.second + dir[i][1];
				if (tx < 0 || ty < 0 || tx >= grid.size() || ty >= grid[0].size() || visited[tx][ty]) continue;
				if (grid[tx][ty] == 1 && !visited[tx][ty]) {
					que.emplace(tx, ty);
					visited[tx][ty] = true;
					area++;
				}
			}
		}
		return area;
	}
};
int main() {


	return 0;
}