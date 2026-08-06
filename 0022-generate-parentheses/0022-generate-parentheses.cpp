class Solution {
public:
    vector<string> ans;
    int n;

    void solve(int i, int openUsed, int cnt, string &curr) {
        if (i == n) {
            if (cnt == 0)
                ans.push_back(curr);
            return;
        }

        // Place '(' only if we haven't used all N opening brackets
        if (openUsed < n / 2) {
            curr.push_back('(');
            solve(i + 1, openUsed + 1, cnt + 1, curr);
            curr.pop_back();
        }

        // Place ')' only if there is an unmatched '('
        if (cnt > 0) {
            curr.push_back(')');
            solve(i + 1, openUsed, cnt - 1, curr);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int N) {
        n = 2 * N;
        string curr;
        solve(0, 0, 0, curr);
        return ans;
    }
};