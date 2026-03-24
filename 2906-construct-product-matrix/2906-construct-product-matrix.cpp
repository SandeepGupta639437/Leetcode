class Solution {
public:
    using ll = long long;
    int MOD = 12345;
    vector<vector<int>>constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sz = m * n;
        vector<ll> pref(sz+1, 1), suf(sz+1, 1);

        int k = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pref[k] = (pref[k-1] * grid[i][j]) % MOD;
                k++;
            }
        }

        k = sz-1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){ 
                suf[k] = (suf[k+1] * grid[i][j]) % MOD;
                k--;
            }
        }

        k=1;
        vector<vector<int>> ans(m, vector<int>(n));

        k = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = (pref[k-1] * suf[k]) % MOD; 
                k++;
            }
        }

        return ans;
    }
};