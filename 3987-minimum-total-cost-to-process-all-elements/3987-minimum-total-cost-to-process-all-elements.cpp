class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long cnt = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long energy = k;

        for (int i = 0; i < n; i++) {
            if (nums[i] > energy) {
                long long d = (1LL * nums[i] - energy + k - 1) / k;
                cnt += d;
                energy += d * k;
            }
            energy -= nums[i];
        }
        long long a = cnt%MOD;
        long long  b = (cnt+1)%MOD;
        if(a%2==0){
            a/=2;
        }else{
            b/=2;
        }
        return (a*b)%MOD;
    }
};