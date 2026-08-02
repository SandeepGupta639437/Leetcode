class Solution {
public:
    long long gcd(long long a,long long b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    long long maxPairStrength(vector<int>& nums) {
        long long  ans  = 0;
        int n =  nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long gCD = gcd(nums[i],nums[j]);
                long long temp = (nums[i] / gCD) * 1LL * (nums[j] / gCD);
                ans  = max(ans,temp);
            }
        }
        return ans;
    }
};