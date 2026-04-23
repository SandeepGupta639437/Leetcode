class Solution {
public:
    using ll = long long;

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<ll> ans(n, 0);

        for (auto &it : mp) {
            auto &v = it.second;
            int m = v.size();

            vector<ll> pref(m);
            pref[0] = v[0];
            for (int i = 1; i < m; i++) {
                pref[i] = pref[i - 1] + v[i];
            }

            for (int i = 0; i < m; i++) {
                ll left = 0, right = 0;
                if (i > 0){
                   left = (ll)i * v[i] - pref[i - 1];
                }
                if (i < m - 1){
                    right = (pref[m - 1] - pref[i]) - (ll)(m - i - 1) * v[i];
                }

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};