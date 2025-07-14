#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int fast = 0, slow = 0;
        for (fast = 0; fast < len; fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
vector<int> v = {1,2,3,3,5,6,7,8,3,9};
int main() {
    Solution s;
    int res = s.removeElement(v, 3);
    for (int i = 0; i < res; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

}