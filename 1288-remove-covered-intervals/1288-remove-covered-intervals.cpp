class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {

        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];   // larger end first
            return a[0] < b[0];       // smaller start first
        });

        int n = v.size();
        int cnt = n;

        int x = v[0][0];
        int y = v[0][1];

        for (int i = 1; i < n; i++) {
            if (v[i][0] >= x && v[i][1] <= y) {
                cnt--;
            } else {
                x = v[i][0];
                y = v[i][1];
            }
        }

        return cnt;
    }
};