class Solution {
public:
    vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0,0}});

        while(!pq.empty()){

            auto [cost,p] = pq.top();
            pq.pop();

            auto [x,y] = p;

            if(cost > dist[x][y]) continue;

            if(x==m-1 && y==n-1)
                return cost < health;

            for(auto &d:dir){

                int nx=x+d[0];
                int ny=y+d[1];

                if(nx<0||ny<0||nx>=m||ny>=n)
                    continue;

                int newCost = cost + grid[nx][ny];

                if(newCost < dist[nx][ny]){
                    dist[nx][ny]=newCost;
                    pq.push({newCost,{nx,ny}});
                }
            }
        }

        return false;
    }
};