#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        //dp[i]表示爬上第i层台阶一共有dp[i]种方法
        vector<int> dp(n+1, 0);
        if (n==1)
            return 1;
        else if (n==2)
            return 2;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
       if (n>2)
           return climbStairs(n-1) + climbStairs(n-2);
       else if (n==1)
           return 1;
        else if (n==2)
            return 2;
    }
};


int main()
{
    int pier;
    cin >> pier ;
    Solution s;
    cout << s.climbStairs(pier) << endl;
    Solution s2;
    cout << s2.climbStairs(pier) << endl;

    return 0;
}