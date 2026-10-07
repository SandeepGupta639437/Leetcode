class Solution {
public:
    set<string> ans;
    int n;

    void solve(int i, string &s, string &temp, int cnt, int leftRemove, int rightRemove) {

        if(cnt < 0) return;

        if(i == n) {
            if(cnt == 0 && leftRemove == 0 && rightRemove == 0) ans.insert(temp);
            return;
        }

        if(s[i] == '(') {

            // Remove '('
            if(leftRemove > 0) solve(i + 1, s, temp, cnt, leftRemove - 1, rightRemove);

            // Keep '('
            temp.push_back('(');
            solve(i + 1, s, temp, cnt + 1, leftRemove, rightRemove);
            temp.pop_back();

        }
        else if(s[i] == ')') {

            // Remove ')'
            if(rightRemove > 0) solve(i + 1, s, temp, cnt, leftRemove, rightRemove - 1);

            // Keep ')'
            if(cnt > 0) {
                temp.push_back(')');
                solve(i + 1, s, temp, cnt - 1, leftRemove, rightRemove);
                temp.pop_back();
            }

        }
        else {
            // Normal character
            temp.push_back(s[i]);
            solve(i + 1, s, temp, cnt, leftRemove, rightRemove);
            temp.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        n = s.size();

        int leftRemove = 0;
        int rightRemove = 0;

        // Calculate minimum removals
        for(char ch : s) {

            if(ch == '(') {
                leftRemove++;
            }
            else if(ch == ')') {

                if(leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string temp = "";

        solve(0, s, temp, 0, leftRemove, rightRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};