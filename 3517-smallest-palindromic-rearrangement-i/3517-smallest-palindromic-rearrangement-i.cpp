class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string left(s.begin(), s.begin() + n / 2);

        sort(left.begin(), left.end());

        string ans = left;

        if(n&1) ans += s[n / 2];

        reverse(left.begin(), left.end());
        ans += left;

        return ans;
    }
};