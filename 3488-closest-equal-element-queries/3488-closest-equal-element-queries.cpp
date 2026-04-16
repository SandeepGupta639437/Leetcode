class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& v = mp[nums[q]];

            int m = v.size();

            // only one occurrence
            if (m == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
            int res = INT_MAX;

            // left neighbor
            int left = v[(pos - 1 + m) % m];
            int d1 = abs(q - left);
            res = min(res, min(d1, n - d1));

            // right neighbor
            int right = v[(pos + 1) % m];
            int d2 = abs(q - right);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }

        return ans;
    }
};