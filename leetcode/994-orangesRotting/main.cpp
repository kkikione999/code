#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution2 {
public:
	int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>> rot_oranges;
		//找到所有的烂橘子
		int good = 0;
		int bad = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 2) {
					bad++;
					rot_oranges.emplace(i,j);
				}
				else if (grid[i][j] == 1) {
					good++;
				}
			}
		}
		//如果没有腐烂的橘子，直接返回
		if (rot_oranges.empty()) return 0;
		vector<pair<int, int>> visited;
		int time = 0;
		while (!rot_oranges.empty() && good == 0) {
			int size = rot_oranges.size();
			time ++;
			for (int i = 0; i < size; i++) {
				pair<int, int> next = rot_oranges.front();
				rot_oranges.pop();
				//

				for (int j = 0; j < 4; j++) {
					int tx = next.first + dir[i][0];
					int ty = next.second + dir[i][1];
					//越界
					if (tx < 0 || ty < 0 || tx >= grid.size() || ty >= grid[0].size() ) continue;
					//遇到新鲜的橘子 加入队列 并且把它腐烂！！！
					if (grid[tx][ty] == 1) {
						grid[tx][ty] = 2;
						good--;
						rot_oranges.emplace(tx, ty);
					}
				}
			}
		}
		if (good > 0 )return -1;
		return time;
	}
};
class Solution {
public:
	int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int orangesRotting(vector<vector<int>>& grid) {
		if (grid[0].empty()) return 0;
		if (grid.size() == 1 && grid[0].size() == 1) {
			if (grid[0][0] == 1 ) return -1;
			if (grid[0][0] == 2 || grid[0][0] == 0) return 0;
		}
		int time = 0;
		int fresh = 0;
		queue<pair<int, int>> rot_oranges;

		//计算好橘子的数量和坏橘子的坐标
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					fresh++;
				}
				else if (grid[i][j] == 2) {
					rot_oranges.emplace(i, j);
				}
			}
		}

		while (!rot_oranges.empty() && fresh > 0) {
			time ++ ;
			int size = rot_oranges.size();
			//腐化下一层的橘子
			for (int i = 0; i < size; i++) {
				pair<int, int> next = rot_oranges.front();
				rot_oranges.pop();
				for (int j = 0; j < 4; j++) {
					int tx = next.first + dir[j][0];
					int ty = next.second + dir[j][1];
					//越界
					if (tx < 0 || ty < 0 || tx >= grid.size() || ty >= grid[0].size()) continue;
					if (grid[tx][ty] == 1) {
						grid[tx][ty] = 2;
						fresh--;
						rot_oranges.emplace(tx, ty);
					}
				}
			}
		}
		if (fresh > 0) {
			return -1;
		}
		return time;
	}
};

int main() {



	return 0;
}