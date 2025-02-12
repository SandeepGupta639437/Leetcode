#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int digitsum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int maxSum = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int dsum = digitsum(nums[i]); // Compute digit sum once

            if (mpp.find(dsum) != mpp.end()) { 
                maxSum = max(maxSum, mpp[dsum] + nums[i]); // Update maxSum
            }
            // Store the maximum value for this digit sum
            mpp[dsum] = max(mpp[dsum], nums[i]);
        }

        return maxSum;
    }
};
