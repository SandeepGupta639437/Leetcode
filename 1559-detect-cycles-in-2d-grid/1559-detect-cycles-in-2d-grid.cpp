class Solution {
public:
    vector<int> parent, size;

    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]); // path compression
    }

    // return true if cycle detected
    bool Union(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return true; // cycle

        if (size[a] < size[b]) swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m * n);
        size.resize(m * n);

        for (int i = 0; i < m * n; i++) {
            make(i);
        }

        auto id = [&](int i, int j) {
            return i * n + j;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // check right
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    if (Union(id(i, j), id(i, j + 1))) return true;
                }

                // check down
                if (i + 1 < m && grid[i][j] == grid[i + 1][j]) {
                    if (Union(id(i, j), id(i + 1, j))) return true;
                }
            }
        }

        return false;
    }
};