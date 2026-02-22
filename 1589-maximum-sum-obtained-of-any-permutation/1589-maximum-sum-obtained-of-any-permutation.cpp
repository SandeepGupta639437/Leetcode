class Solution {
public:
  const long long MOD = 1000000007;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {int n=nums.size();
        vector<int>idxFreq(n,0);
        for(int i=0;i<requests.size();i++){
          idxFreq[requests[i][0]] += 1;
          if(requests[i][1]+1<n)
          idxFreq[requests[i][1]+1] -= 1;
        }
        for(int i=1;i<n;i++){
         idxFreq[i] += idxFreq[i-1];
        }
        long long sum=0;
        sort(nums.begin(),nums.end(),greater<int>());
        sort(idxFreq.begin(),idxFreq.end(),greater<int>());
        for(int i=0;i<n;i++){
            sum = (sum + 1LL * idxFreq[i] * nums[i]) % MOD;
        }
        return sum;
    }
};