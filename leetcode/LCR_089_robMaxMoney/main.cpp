#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
    /*
     * dp[i] 表示打劫到第i家说获得的最大金额
     * dp[i] 表示可以打劫第i家，也可以不打劫第i家
     * 打劫第i家: nums[i] + dp[i-2];
     * 不打劫第i家: dp[i-1]
     * max(打劫第i家，不打劫第i家)
     */
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if (nums.size() == 1) return nums[0];
        dp[1] = max(nums[0], nums[1]);
        if (nums.size() == 2) return max(dp[0], dp[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        cout << "below is dp array" << endl;
        for (int i = 0; i < dp.size(); i++)
        {
            cout << dp[i] << endl;
        }
        cout << endl;

        return dp[nums.size()-1];
    }
};


int main()
{
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n') {
            break;
        }
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    Solution s;
    cout << s.rob(nums);
    return 0;
}