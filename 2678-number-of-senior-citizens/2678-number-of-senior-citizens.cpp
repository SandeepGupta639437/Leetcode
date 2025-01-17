class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int sum = (details[i][11]-'0')*10+(details[i][12]-'0');
            if (sum > 60) cnt++;
        }
        return cnt;
    }
};
