#include <iostream>
#include <vector>

using namespace std;
vector<int> nums = {-7,-3,2,3,11};
class Solution {
public:
    #define abs(x) ((x) > 0 ? (x) : -(x))
    #define sqr(x) (x) * (x)
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        int front = 0, rear = nums.size() - 1;
        int back = rear;
        while (front <= rear) {
            if (abs(nums[front]) > abs(nums[rear])) {
                res[back--] = sqr(nums[front]);
                front++;
            }else {
                res[back--] = sqr(nums[rear]);
                rear--;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int>res = s.sortedSquares(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}