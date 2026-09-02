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
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int OFFSET = 10001;

        // 0 ... 10000        -> rows
        // 10001 ... 20001    -> columns
        DSU dsu(20002);

        // Initially we have 20002 components,
        // but we only care about nodes that actually occur.
        
        unordered_set<int> used;

        for(auto &stone : stones) {
            int x = stone[0];
            int y = stone[1] + OFFSET;

            dsu.Union(x, y);

            used.insert(x);
            used.insert(y);
        }

        // Count components among only used row/column nodes
        unordered_set<int> roots;

        for(int node : used) {
            roots.insert(dsu.find(node));
        }

        int components = roots.size();

        return stones.size() - components;
    }
};