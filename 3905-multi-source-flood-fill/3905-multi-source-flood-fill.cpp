class Solution {
public:

    vector<vector<int>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> grid(n, vector<int>(m, 0));

        queue<pair<int,int>> que;

        // sort by color descending
        sort(sources.begin(), sources.end(),
            [&](auto &a, auto &b){
                return a[2] > b[2];
            });

        // initialize sources
        for(auto &src : sources){

            int r = src[0];
            int c = src[1];
            int color = src[2];

            grid[r][c] = color;

            que.push({r,c});
        }

        while(!que.empty()){

            int sz = que.size();

            while(sz--){

                auto curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir : directions){

                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if(ni >= 0 && nj >= 0 &&
                       ni < n && nj < m &&
                       grid[ni][nj] == 0){

                        grid[ni][nj] = grid[i][j];

                        que.push({ni,nj});
                    }
                }
            }
        }

        return grid;
    }
};