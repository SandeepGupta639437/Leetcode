class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0,minSum =0;
        int currSum = 0;
        for(int i : nums){
            currSum = max(i,currSum+i);
            maxSum = max(maxSum,currSum);
        }
        currSum = 0;
        for(int i : nums){
            currSum = min(i,currSum+i);
            minSum = min(minSum,currSum);
        }
        return max(maxSum,abs(minSum));
    }
};