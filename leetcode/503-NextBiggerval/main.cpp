#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    // 拼接一个新的nums
    vector<int> nums1(nums.begin(), nums.end());
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    // 用新的nums大小来初始化result
    vector<int> result(nums.size(), -1);
    if (nums.size() == 0) return result;

    // 开始单调栈
    stack<int> st;
    st.push(0);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[st.top()]) st.push(i);
      else if (nums[i] == nums[st.top()]) st.push(i);
      else {
        while (!st.empty() && nums[i] > nums[st.top()]) {
          result[st.top()] = nums[i];
          st.pop();
        }
        st.push(i);
      }
    }
    // 最后再把结果集即result数组resize到原数组大小
    result.resize(nums.size() / 2);
    return result;

  }
};


int main()
{



}