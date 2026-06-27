class Solution {
public:
    using ll=long long;
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>prefix(2*n+1,0);
        prefix[n]=1;
        int cnt=n;
        ll presum=0;
        ll ans=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==target){
                presum+=prefix[cnt];
                cnt++;
                prefix[cnt]++;
            }else{
                cnt--;
                presum-=prefix[cnt];
                prefix[cnt]++;
            }
            ans+=presum;
        }
        return ans;
    }
};