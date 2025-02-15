class Solution {
public:
    bool fun(int i, string s, int x) {
        if (i == s.size() && x == 0) return true;
        bool res = false;

        for (int j = i; j < s.size(); j++) {
            int cv = stoi(s.substr(i, j - i + 1));
            if (cv > x) break;
            res = fun(j + 1, s, x - cv);
            if (res) return true;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int ts = 0, i, x;
        for (i = 1; i <= n; i++) {
            x = i * i;
            string s = to_string(x);
            if (fun(0, s, i)) ts += x;
        }
        return ts;
    }
};
