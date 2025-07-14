#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int pointer1 = 0, pointer2 = 0;
		int temp = 0;
		int head = 0, tail = k-1;
		if (nums.size() == 1) {
			return nums;
		}
		if (k == 1) return nums;
		vector<int> result(nums.size()-(k-1),0);
		int size = nums.size()-(k-1);
		for (int i = 0; i < size ; i++, head++, tail++) {
			while (temp != tail) {
				temp ++;
				if (nums[temp] >= nums[pointer1]) {
					pointer2 = pointer1;
					pointer1 = temp;
				}
				else if (nums[temp] >= nums[pointer2]) {
					pointer2 = temp;
				}
			}
		}
		return result;
	}

};
class Solution2 {
	//gpt题解
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq; // 存储的是元素下标
		vector<int> result;

		for (int i = 0; i < nums.size(); ++i) {
			// 移除超出窗口范围的元素索引
			while (!dq.empty() && dq.front() <= i - k) {
				dq.pop_front();
			}

			// 移除比当前元素小的元素索引（因为它们不可能是最大值）
			while (!dq.empty() && nums[dq.back()] < nums[i]) {
				dq.pop_back();
			}

			dq.push_back(i);

			// 窗口形成后才记录结果
			if (i >= k - 1) {
				result.push_back(nums[dq.front()]);
			}
		}

		return result;
	}
};


int main() {
	vector<int> nums = {1,-9,8,-6,6,4,0,5};
	Solution2 s;
	s.maxSlidingWindow(nums,4);




	return 0;
}