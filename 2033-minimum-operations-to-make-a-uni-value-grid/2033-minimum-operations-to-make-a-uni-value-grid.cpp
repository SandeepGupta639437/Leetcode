class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> a;
        int rem = grid[0][0] % x;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] % x != rem) return -1;
                a.push_back(grid[i][j]);
            }
        }

        int mid = (n * m) / 2;

        nth_element(a.begin(), a.begin() + mid, a.end()); // FIX

        int median = a[mid];
        int ans = 0;

        for (int val : a) {
            ans += abs(val - median) / x;
        }

        return ans;
    }
};