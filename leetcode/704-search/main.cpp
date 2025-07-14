#include <iostream>
#include <vector>

using namespace std;
vector<int> v = {1,3,4,5,7,9,21,33,42,65};
class Solution {
    public:
    int search(vector<int>& nums, int target) {
        //左闭右闭[1,2,3,4,5,6,7]
        int right = nums.size() - 1;
        int left = 0;
        int middle;
        while (left <= right ) {
            //left可以等于right，因为是闭区间
            middle = (left + right) / 2;
            if (nums[middle]>target) {
                right = middle-1;
            }
            else if (nums[middle]<target) {
                left = middle+1;
            }
            else
                return middle;
        }
        return -1;
    }
    int search2(vector<int>& nums, int target) {
        //左闭右开[1,2,3,4,5,6,7)
        int left = 0,right = nums.size();
        int middle;
        while (left < right) {
            //left不能等于right，因为是开区间
            middle = (left + right) / 2;
            if (nums[middle]>target) {
                right = middle;
            }
            else if (nums[middle]<target) {
                left = middle+1;
            }
            else
                return middle;
        }
        return -1;
    }
};

class solution_traning {
    public:
    int search(vector<int>& nums, int target) {
        //左闭右闭
        int left = 0,right = nums.size()-1;
        int middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle]>target) {
                right = middle-1;
            }
            else if (nums[middle]<target) {
                left = middle+1;
            }
            else
                return middle;
        }
        return -1;
    }
    int search2 (vector<int>& nums, int target) {
        //左闭右开
        int left = 0,right = nums.size();
        int middle;
        while (left<right) {
            middle = (left + right) / 2;
            if (nums[middle]>target) {
                right = middle;
            }
            else if (nums[middle]<target) {
                left = middle+1;
            }
            else
                return middle;
        }
        return -1;
    }
};


int main () {
    // Solution s;
    // int out = s.search2(v, 7);
    // cout << out << endl;
    solution_traning s2;
    int out2 = s2.search2(v,65);
    cout << out2 << endl;
    return 0;
}