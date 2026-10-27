class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string>ans(n,string(m, '#'));
        for (int i=0;i<m;i++)ans[0][i] = '.';
        for (int i=0;i<n;i++)ans[i][m-1] = '.';
        return ans;
    }
};