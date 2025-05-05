#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];

    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout << s.fib(n) << endl;

    return 0;
}