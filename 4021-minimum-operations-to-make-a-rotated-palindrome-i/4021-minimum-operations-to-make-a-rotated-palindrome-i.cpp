class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        s += s;

        int ans = INT_MAX;

        for(int start = 0; start < n; start++) {
            int cost = start;

            for(int j = 0; j < n / 2; j++) {
                char a = s[start + j];
                char b = s[start + n - 1 - j];

                int x = (a - b + 26) % 26;
                int y = (b - a + 26) % 26;

                cost += min(x, y);
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};