class Solution {
public:
    long long MOD = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int j = 0;

            while (x) {
                if (x & 1) mpp[j]++;
                x >>= 1;
                j++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long temp = 0;

            for (int j = 0; j < 32; j++) {
                if (mpp[j] > 0) {
                    temp |= (1LL << j);
                    mpp[j]--;
                }
            }

            ans = (ans + temp * temp) % MOD;
        }

        return ans;
    }
};