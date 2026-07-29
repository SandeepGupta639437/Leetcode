class Solution {
public:
    using ll = long long;
    const ll LIMIT = 1000001;

    vector<ll> fact;

    // nCr with limit
    ll comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        ll ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIMIT) return LIMIT;
        }
        return min(ans, LIMIT);
    }

    // Number of distinct permutations of multiset
    ll countWays(vector<int>& cnt) {

        int total = 0;
        for (int x : cnt) total += x;
        ll ways = 1;
        int rem = total;

        for (int x : cnt) {

            if (x == 0) continue;
            ways *= comb(rem, x);
            if (ways > LIMIT)  ways = LIMIT;
            rem -= x;
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] & 1) mid = char('a' + i);
        }

        int len = 0;

        for (int x : half) len += x;

        string first = "";

        for (int pos = 0; pos < len; pos++) {

            bool found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                ll ways = countWays(half);

                if (ways >= k) {
                    first.push_back(char('a' + c));
                    found = true;
                    break;
                }

                k -= ways;
                half[c]++;
            }

            if (!found) return "";
        }

        string second = first;
        reverse(second.begin(), second.end());

        if (mid) return first + mid + second;

        return first + second;
    }
};