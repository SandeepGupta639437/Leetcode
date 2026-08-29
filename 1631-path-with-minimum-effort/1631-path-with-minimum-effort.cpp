class Solution {
public:
    vector<vector<int>> direction{ {1,0}, {0,-1}, {0,1}, {-1,0} };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // dist[i][j] = minimum effort required to reach (i,j)
        vector<vector<int>> dist( m, vector<int>(n, INT_MAX) );

        // {effort, {x, y}}
        priority_queue< pair<int,pair<int,int>>   ,  vector<pair<int, pair<int,int>>>  ,  greater<pair<int, pair<int,int>>> > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();

            auto [x, y] = pos;

            // If we reached destination
            if (x == m-1 && y == n-1) return effort;

            // Ignore outdated entry
            if (effort > dist[x][y]) continue;

            for (auto &d : direction) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)  continue;

                int edgeEffort = abs( heights[x][y] - heights[nx][ny] );

                // Effort of this complete path
                int newEffort = max(effort, edgeEffort);

                if (newEffort < dist[nx][ny]) {
                    dist[nx][ny] = newEffort;

                    pq.push({ newEffort, {nx, ny} });
                }
            }
        }

        return 0;
    }
};