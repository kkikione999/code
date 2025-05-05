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
    int uniquePaths(int m, int n) {
        if(n<0) return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) {
          dp[i][0] = 1;
        }
        for (int j = 1; j < n; j++) {
          dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for(int j = 1;j < n; j++) {
              dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];

    }
};
int main() {







  return 0;
}