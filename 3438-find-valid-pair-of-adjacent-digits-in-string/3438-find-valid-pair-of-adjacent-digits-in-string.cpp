class Solution {
public:
    string findValidPair(string s) {
        unordered_map<int, int> ma;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            ma[s[i] - '0']++;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != s[i + 1] && s[i] - '0' == ma[s[i] - '0'] &&
                s[i + 1] - '0' == ma[s[i + 1] - '0']) {
                ans += s[i];
                ans += s[i + 1];
                break;
            }
        }
        return ans;
    }
};