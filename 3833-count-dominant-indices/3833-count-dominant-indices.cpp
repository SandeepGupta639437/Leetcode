class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffAvg(n,0);

        int sum = 0;
        int cnt = 0;

        for(int i= n-1;i>=0;i--){
            sum+=nums[i];
            cnt++;
            suffAvg[i] = sum/cnt;
        }
        int ans = 0;

        for(int i=0;i<n-1;i++){
            if(nums[i] > suffAvg[i])ans++;
        }

        return ans;
    }
};