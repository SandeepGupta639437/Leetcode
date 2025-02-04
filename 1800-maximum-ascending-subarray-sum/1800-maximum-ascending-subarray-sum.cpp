class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Edge case: empty array
        
        int currSum = nums[0], maxSum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];
            } else {
                maxSum = max(maxSum, currSum);
                currSum = nums[i]; // Start a new subarray
            }
        }
        return max(maxSum, currSum); // Ensure the last subarray is considered
    }
};
