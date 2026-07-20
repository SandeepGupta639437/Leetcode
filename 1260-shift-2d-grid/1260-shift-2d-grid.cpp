class Solution {
public:
    int N ;
    void rotateRight(vector<int>& v,int k){
        k = k%N;
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+k);
        reverse(v.begin()+k,v.end());
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        N = m*n;

        vector<int>v(m*n);
        int l = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[l] = grid[i][j];
                l++;
            }
        }

        rotateRight(v,k);
        l = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = v[l] ;
                l++;
            }
        }

        
        return grid;
    }
};