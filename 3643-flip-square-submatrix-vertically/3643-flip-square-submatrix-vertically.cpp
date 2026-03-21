class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int track=1;
        for(int i=x;i<x+(k+1)/2;i++){
            if(x+k-track == i)return grid;
            for(int j=y;j<y+k;j++){
                int temp = grid[i][j];
                grid[i][j]=grid[x+k-track][j];
                grid[x+k-track][j]=temp;
            }
            track++;
        }
        return grid;
    }
};