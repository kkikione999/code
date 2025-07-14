#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>&nums1, vector<int>&nums2) {
    unordered_set<int>  s(nums1.begin(), nums1.end());
    unordered_set<int> res_set;
    for(int i=0;i<nums2.size();i++) {
        if (s.find(nums2[i]) != s.end()) {
            res_set.insert(nums2[i]);
        }
    }
    vector<int> res(res_set.begin(), res_set.end());
    return res;
}
#define LEN_MAX 1024
class Solution {
public:
    vector<int> intersection2(vector<int>&nums1, vector<int>&nums2) {
        vector<int> hash_vector(1024,0);
        unordered_set<int> res_set;
        for (int i = 0; i < nums1.size(); i++) {
            hash_vector[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (hash_vector[nums2[i]] == 1) {
                res_set.insert(nums2[i]);
            }
        }
        vector<int> res(res_set.begin(), res_set.end());
        return res;
    }
};

int main() {


    return 0;
}