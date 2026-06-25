#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mpp[complement] != 0) {
                return {mpp[complement]-1, i}; 
            }
            mpp[nums[i]] = i+1;
        }
        return {};
    }
};
