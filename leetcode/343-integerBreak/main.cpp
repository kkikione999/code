#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
#define max(a,b) (((a) > (b)) ? (a) : (b))
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 3 ; i <= n ; i++) {
            max(dp[i] ,dp[i-1]*dp[i-2]);

        }

    }
};

int main() {
    Solution s;
}


