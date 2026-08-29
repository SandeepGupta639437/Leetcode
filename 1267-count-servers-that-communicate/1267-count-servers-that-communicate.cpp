//With DSU Approach
class DSU {
public:
    vector<int> parent;
    vector<int> sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if(parent[v] == v)
            return v;

        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if(a != b) {
            if(sz[a] < sz[b])
                swap(a, b);

            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        DSU dsu(m * n);

        auto id = [&](int i, int j) {
            return i * n + j;
        };

        vector<int> row(m, -1);
        vector<int> col(n, -1);

        // Connect servers in the same row
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    int curr = id(i, j);

                    if(row[i] != -1) {
                        dsu.Union(curr, row[i]);
                    }
                    else {
                        row[i] = curr;
                    }
                }
            }
        }

        // Connect servers in the same column
        for(int j = 0; j < n; j++) {

            for(int i = 0; i < m; i++) {

                if(grid[i][j] == 1) {

                    int curr = id(i, j);

                    if(col[j] != -1) {
                        dsu.Union(curr, col[j]);
                    }
                    else {
                        col[j] = curr;
                    }
                }
            }
        }

        // Count servers which belong to a component
        // containing at least 2 servers
        vector<int> cnt(m * n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    int root = dsu.find(id(i, j));
                    cnt[root]++;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    int root = dsu.find(id(i, j));

                    if(cnt[root] > 1)
                        ans++;
                }
            }
        }

        return ans;
    }
};