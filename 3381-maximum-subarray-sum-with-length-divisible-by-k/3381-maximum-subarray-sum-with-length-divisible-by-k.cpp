class Solution {
public:
    using ll = long long;
    ll maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>prefSum(n);
        prefSum[0] = nums[0];

        for(int i=1;i<n;i++){
            prefSum[i] = prefSum[i-1] + nums[i];
        }

        ll result =  LLONG_MIN;

        for(int i=0;i<k;i++){
            ll currSum = 0;
            
            int j = i;

            while(j<n && j+k-1<n){
               int l = j+k-1;
               ll subSum = prefSum[l] -((j>0)? prefSum[j-1]:0);
               currSum = max(subSum,currSum+subSum);
               result = max(result,currSum);
               j+=k;
            }
        }
        return result;
    }
};