class Solution {
public:
    typedef pair<int,pair<int,int>> PP;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        priority_queue<PP,vector<PP>,greater<PP>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.push({grid[0][0], {0,0}});
        visited[0][0] = true;

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();

            int height = x.first;
            int i = x.second.first;
            int j = x.second.second;

            ans = max(ans,height);

            if(i==m-1 && j==n-1)return ans;

            for(auto &dir: directions){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i>=0 && new_i<m && new_j>=0 && new_j < n && !visited[new_i][new_j]){
                    visited[new_i][new_j] = true;
                    pq.push({grid[new_i][new_j],{new_i,new_j}});
                }
            }
        }
        return ans;
    }
};



