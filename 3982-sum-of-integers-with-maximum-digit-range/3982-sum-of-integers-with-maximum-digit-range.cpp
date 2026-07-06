class Solution {
public:
    int max_range = 0;
    int range(int n){
        int maxi = 0;
        int mini = INT_MAX;
        while(n){
            int d = n%10;
            maxi = max(maxi,d);
            mini = min(mini,d);
            n/=10;
        }
        max_range = max(max_range,maxi-mini);
        return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[range(nums[i])]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(range(nums[i])==max_range)ans+=nums[i];
        }
        return ans;
        
    }
};