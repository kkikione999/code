#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> cost{10,15,20};

/*
 * dp[i]:表示爬到第i层楼梯需要的花费
 * dp[i] = dp[i-1] + cost[i-1]
 * de[i] = dp[i-2] + cost[i-2]
 * 目的：爬到top : cost.size()层, dp[cost.size()]最小
 * */

#define min(a,b) (a)<(b)?(a):(b)

int minCostClimbingStairs(vector<int>& cost) {
  vector<int> dp(cost.size()+1, 0);
  dp[0] = 0;
  dp[1] = 0;
  int i;

  for (i = 2; i <= cost.size(); i++) {
    dp[i] = min( dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
  }
  for(auto it : dp) {
    cout << it << " ";
  }
  cout << endl;
  return dp.back();
}

int main(){

  int i = minCostClimbingStairs(cost);
  cout<<endl;
  cout << "min spend " << i << endl;

  return 0;
}