#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) (((a)>(b))?(a):(b))

int maxValue(vector<vector<int>> &items, int capacity)
{
    /* 定义一个二维的dp数组 有items.size()行， capacity+1列
     * dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和的最大值为dp[i][j]
     * 递推公式：放入物品i/不放物品i dp[i][j] = max(不取物品i,取物品i)
     * 不放物品i value = dp[i-1][j]
     * 放物品i value = dp[i-1][j-items[i][0](物品i的重量)] + items[i][1]
     */
    vector<vector<int>> dp(items.size(), vector<int>(capacity+1, 0));
    for (int i = 0; i <= capacity; i++)
    {
        if (items[0][0] <= i)
            dp[0][i] = items[0][1];
        else
            dp[0][i] = 0;
    }
    // cout <<"below is pd initialed" << endl;
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[0].size(); j++)  cout << dp[i][j] << " " ;
    //     cout << endl;
    // }

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            int val1, val2;
            val1 = dp[i-1][j];
            if (j-items[i][0] >= 0)
                val2 = dp[i-1][j-items[i][0]] + items[i][1];
            else
                val2 = -1;
            dp[i][j] = max(val1, val2);
        }
    }
    // cout <<"below is pd listed" << endl;
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[0].size(); j++)  cout << dp[i][j] << " " ;
    //     cout << endl;
    // }
     cout << dp[dp.size()-1][capacity];
    return dp[dp.size()-1][capacity];

}


int main()
{
    //M为种类，N为背包行李空间
    int M,N;
    cin >> M >> N;
    /*定义一个M行2列的二维数组，第一个参数就是所占空间，第二个参数是价值*/
    vector<vector<int>> items(M, vector<int>(2, 0));
    for (int i = 0; i < M; i++)//输入所占的空间
    {
        cin >> items[i][0];
    }
    for (int i = 0; i < M; i++)//输入价值
    {
        cin >> items[i][1];
    }
    // for (int i = 0; i < M; i++)
    //     cout << items[i][0] << " " << items[i][1] << endl;
    maxValue(items, N);


    return 0;
}
