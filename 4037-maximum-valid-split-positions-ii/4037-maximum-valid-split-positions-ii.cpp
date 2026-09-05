class Solution {
public:
    int solve(vector<int>& prefix, vector<int>& suffix, int skip,vector<int>&a) {
        int n = a.size();

        for (int i = 1; i <= n; i++) {
            if (i - 1 == skip) {
                prefix[i] = prefix[i - 1];
                continue;
            }
            prefix[i] = gcd(prefix[i - 1], a[i - 1]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == skip) {
                suffix[i] = suffix[i + 1];
                continue;
            }
            suffix[i] = gcd(suffix[i + 1], a[i]);
        }
        int curr = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i == skip)
                continue;
            if (prefix[i + 1] == suffix[i + 1])
                curr++;
        }
        return curr;
    }
    int maxValidSplits(vector<int>& a) {

        int n = a.size(), ans = 0;

        vector<int> prefixmain(n + 1, 0);
        for (int i = 1; i <= n; i++){
            prefixmain[i] = gcd(prefixmain[i - 1], a[i - 1]);
        }

        for (int i = 0; i <= n; i++) {
            if (i > 0 && prefixmain[i] == prefixmain[i - 1]) continue;
            
            int skip = i - 1;
            vector<int> prefix(n + 1, 0);
            vector<int> suffix(n + 1, 0);
            ans = max(ans, solve(prefix, suffix, i - 1,a));
        }
        return ans;
    }
};