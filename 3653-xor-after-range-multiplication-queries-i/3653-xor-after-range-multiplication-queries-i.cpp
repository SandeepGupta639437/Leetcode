class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9+7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<ll> mul(n, 1);

        int B = sqrt(n);

        for (auto &q : queries) {
            int l = q[0], r = q[1], step = q[2], val = q[3];

            // large step → few elements
            if (step > B) {
                for (int i = l; i <= r; i += step) {
                    mul[i] = (mul[i] * val) % MOD;
                }
            } 
            // small step → still brute but bounded
            else {
                for (int i = l; i <= r; i += step) {
                    mul[i] = (mul[i] * val) % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ll val = (nums[i] * mul[i]) % MOD;
            ans ^= val;
        }

        return ans;
    }
};