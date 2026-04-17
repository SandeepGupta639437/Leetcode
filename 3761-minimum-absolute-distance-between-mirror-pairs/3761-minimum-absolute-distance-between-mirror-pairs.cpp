class Solution {
public:
    int rever(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();

        // store all indices
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int rev = rever(nums[i]);

            if (mpp.find(rev) == mpp.end()) continue;

            auto &vec = mpp[rev];

            // find first index > i
            auto it = upper_bound(vec.begin(), vec.end(), i);

            if (it != vec.end()) {
                ans = min(ans, *it - i);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};