class Solution {
public:
    bool ispossible(int day, vector<int>& bloomDay, int n, int k, int m) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day)
                cnt++;
            else {
                ans += (cnt / k);
                cnt = 0;
            }
        }
        ans += (cnt / k);
        return (ans >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long total = (long long)m * k;  // Check for overflow in multiplication
        if (total > n) return -1; // Not enough flowers

        int ans = -1;
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (ispossible(mid, bloomDay, n, k, m)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
