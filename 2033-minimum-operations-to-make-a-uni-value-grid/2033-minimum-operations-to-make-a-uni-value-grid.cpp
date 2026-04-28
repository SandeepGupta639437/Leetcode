class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>a;
        int rem = grid[0][0]%x;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a.push_back(grid[i][j]);
                if(grid[i][j]%x!=rem)return -1;
            }
        }

        sort(a.begin(),a.end());
        int mid = (n*m)/2;
        int k = a[mid];
        int ans = 0;

        for(int i=0;i<n*m;i++){
            ans+=(abs(k-a[i]))/x;
        }

        return ans;
        
    }
};