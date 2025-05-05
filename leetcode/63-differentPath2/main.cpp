#include <iostream>
#include <vector>
using namespace std;
/*
 * dp[i][j]:表示到(i,j)有dp[i][j]多少种方法
 * dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * i<m
 * j<n
 * m>=1 n<=100
 * */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid[0].size();   //行
        int n = obstacleGrid.size();      //列
        if(n == 0 || m == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(m));
        int block = 0;
        //dp数组行初始化
        block = obstacleGrid[0].size();
        for(int i = 0; i < m; i++)
        {
            if(obstacleGrid[0][i] == 1)
            {
                block = i;
                break;
            }
        }
        for(int j = 0; j < block; j++) dp[0][j] = 1;
        //dp数组列初始化
        block = obstacleGrid.size();
        for(int i = 0; i < n; i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                block = i;
                break;
            }
        }
        for(int j = 0; j < block; j++) dp[j][0] = 1;
        // //初始化是否完成
        // for (auto it : dp)
        // {
        //   for (auto its : it)
        //     cout << its << " ";
        //   cout << endl;
        // }
        //递归
        for (int i=1; i<n ; i++) {
            for (int j=1; j<m ; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        // for (auto it : dp)
        // {
        //   for (auto its : it)
        //     cout << its << " ";
        //   cout << endl;
        // }
        return dp[n-1][m-1];
    }
};


int main() {
  vector<vector<int>> obstacleGrid = {{0,0,0,0},
                                      {0,0,1,0},
                                      {0,1,0,0},
                                      {0,0,0,0}};

  Solution s;
  int result = s.uniquePathsWithObstacles(obstacleGrid);
  cout << result << endl;
  return 0;
}