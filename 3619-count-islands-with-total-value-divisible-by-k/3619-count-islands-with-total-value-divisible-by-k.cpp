class Solution {
public:
    int n, m, d;

    int DFS(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(grid[i][j] == 0) return 0;

        int sum = grid[i][j];
        grid[i][j] = 0;
        sum += DFS(i, j + 1, grid) % d;
        sum += DFS(i + 1, j, grid) % d;
        sum += DFS(i, j - 1, grid) % d;
        sum += DFS(i - 1, j, grid) % d;

        return sum % d;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        d = k;

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0 && DFS(i, j, grid) == 0)
                    ans++;
            }
        }
        return ans;
    }
};