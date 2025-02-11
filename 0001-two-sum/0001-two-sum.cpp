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
            if (mpp.find(complement) != mpp.end()) {
                return {mpp[complement], i}; // Return indices of the two numbers
            }
            mpp[nums[i]] = i; // Store the index of the current number
        }
        return {}; // Return an empty vector if no solution is found
    }
};
