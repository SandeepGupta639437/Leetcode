class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int i, string &digits, string &curr) {
        if (i == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for (char ch : mp[digits[i] - '0']) {
            curr.push_back(ch);
            solve(i + 1, digits, curr);
            curr.pop_back();        // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string curr;
        solve(0, digits, curr);

        return ans;
    }
};