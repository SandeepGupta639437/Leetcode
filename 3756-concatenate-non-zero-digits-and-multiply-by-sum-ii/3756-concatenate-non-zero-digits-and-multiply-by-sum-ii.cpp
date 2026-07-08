class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int m = s.size();

        // Build compressed non-zero string
        string nz = "";
        vector<int> pos;
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                nz += s[i];
                pos.push_back(i);
            }
        }

        int n = nz.size();

        // prefix number
        vector<long long> prefNum(n + 1, 0);
        // prefix digit sum
        vector<long long> prefSum(n + 1, 0);
        // powers of 10
        vector<long long> pow10(n + 1, 1);

        for (int i = 0; i < n; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + (nz[i] - '0')) % MOD;
            prefSum[i + 1] = prefSum[i] + (nz[i] - '0');
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long num = (prefNum[R + 1] - prefNum[L] * pow10[len] % MOD + MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};