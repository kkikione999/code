#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
        int fourSumCount1(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
                int i = 0, j = 0, k = 0, l = 0;
                int len = nums1.size();
                int count = 0;
                for (; i< len; i++) {
                        for (j = 0; j< len; j++) {
                                for (k = 0; k < len; k++) {
                                        for (l = 0; l < len; l++) {
                                                if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0) {
                                                        count++;
                                                }
                                        }
                                }
                        }
                }
                return count;
        }

        int fourSumCount2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
                unordered_multiset<int> nums1_multiset(nums1.begin(), nums1.end());
                unordered_set<int>nums1_set(nums1.begin(), nums1.end());
                vector<int> nums1_vector(nums1_set.begin(), nums1_set.end());

                unordered_multiset<int> nums2_multiset(nums2.begin(), nums2.end());
                unordered_set<int>nums2_set(nums2.begin(), nums2.end());
                vector<int> nums2_vector(nums2_set.begin(), nums2_set.end());

                unordered_multiset<int> nums3_multiset(nums3.begin(), nums3.end());
                unordered_set<int>nums3_set(nums3.begin(), nums3.end());
                vector<int> nums3_vector(nums3_set.begin(), nums3_set.end());

                unordered_multiset<int> nums4_multiset(nums4.begin(), nums4.end());
                unordered_set<int>nums4_set(nums4.begin(), nums4.end());
                vector<int> nums4_vector(nums4_set.begin(), nums4_set.end());
                int count = 0;
                for (int i = 0; i<nums1_vector.size(); i++) {
                        for (int j = 0; j<nums2_vector.size(); j++) {
                                for (int k = 0; k<nums3_vector.size(); k++) {
                                        for (int l = 0; l<nums4_vector.size(); l++) {
                                                if (nums1_vector[i] + nums2_vector[j] + nums3_vector[k] + nums4_vector[l] == 0) {
                                                        count += nums1_multiset.count(nums1_vector[i])*
                                                                 nums2_multiset.count(nums2_vector[j])*
                                                                 nums3_multiset.count(nums3_vector[k])*
                                                                 nums4_multiset.count(nums4_vector[l]);

                                                }
                                        }
                                }
                        }
                }
                return count;
        }

        int fourSumCount3(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
                unordered_multiset<int> sum1;
                unordered_multiset<int> sum2;
                int count = 0;
                for (int i = 0; i < nums1.size(); i++) {
                        for (int j = 0; j < nums2.size(); j++) {
                                sum1.insert(nums1[i] + nums2[j]);
                        }
                }
                for (int i = 0; i < nums3.size(); i++) {
                        for (int j = 0; j < nums4.size(); j++) {
                                sum2.insert(nums3[i] + nums4[j]);
                        }
                }
                // cout << "sum1 0 = " << sum1.count(0) << endl;
                // cout << "sum1-2 = " << sum1.count(-2) << endl;
                // cout << "sum2 0 = " << sum2.count(0) << endl;
                // cout << "sum2 2 = " << sum2.count(2) << endl;
                // cout << "sum2-2 = " << sum2.count(-2) << endl;
                unordered_set<int> peel1_set(sum1.begin(), sum1.end());
                unordered_set<int> peel2_set(sum2.begin(), sum2.end());
                vector<int> peel1_vector(peel1_set.begin(), peel1_set.end());
                vector<int> peel2_vector(peel2_set.begin(), peel2_set.end());
                for (int i = 0; i < peel1_vector.size(); i++) {
                        for (int j = 0; j < peel2_vector.size(); j++) {
                                if (peel1_vector[i] + peel2_vector[j] == 0) {
                                        count += sum1.count(peel1_vector[i])*sum2.count(peel2_vector[j]);
                                }
                        }
                }
                // cout << peel1_vector.size() << endl;
                // cout << peel2_vector.size() << endl;
                return count;
        }

        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
                unordered_map<int, int> sumAB;
                int count = 0;
                for (int a:nums1) {
                     for (int b:nums2) {
                             ++sumAB[a + b];
                     }
                }
                for (int a:nums3) {
                        for (int b:nums4) {
                                if (sumAB.find(-a-b)!=sumAB.end()) {
                                        count += sumAB[-a-b];
                                }
                        }
                }
                return count;
        }
};
int main() {
        vector<int> nums1 = {-1,-1};
        vector<int> nums2 = {-1,1};
        vector<int> nums3 = {-1,1};
        vector<int> nums4 = {1,-1};
        Solution s;
        int res = s.fourSumCount(nums1, nums2, nums3, nums4);
        cout << res << endl;

}