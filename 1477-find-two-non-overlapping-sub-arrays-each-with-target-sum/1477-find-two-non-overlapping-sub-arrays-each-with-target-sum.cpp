class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n + 1, INT_MAX);

        int l = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > target) {
                sum -= arr[l];
                l++;
            }

            best[r + 1] = best[r];

            if (sum == target) {
                int len = r - l + 1;

                if (best[l] != INT_MAX) {
                    ans = min(ans, len + best[l]);
                }

                best[r + 1] = min(best[r + 1], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};