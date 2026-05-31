class Solution {
public:
    int minimumEffort(vector<vector<int>>& t) {
        int l = t.size();
        int ans = 0;
        int remaining = 0;
        sort(t.begin(), t.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]); // descending
             });
        for (int i = 0; i < l; i++) {
            // cout << t[i][0] << "  " << t[i][1] << " "
            //  << ((t[i][0] + 0.0) / (t[i][1])) << "  " << endl;
            if (remaining < t[i][1]) {
                ans += t[i][1] - remaining;
                remaining = max(0, t[i][1] - t[i][0]);
            } else {
                remaining -= t[i][0];
            }

            // cout << ((t[i][0]+ 0.0) / (t[i][1])) << "  " << endl ;
        }
        return ans;
    }
};