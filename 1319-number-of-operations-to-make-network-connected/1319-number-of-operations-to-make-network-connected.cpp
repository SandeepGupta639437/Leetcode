class DSU{
public:
    vector<int>parent;
    vector<int>sz;

    DSU(int n){
        parent.resize(n);
        sz.resize(n);
    }

    void make(int v){
        parent[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        if(parent[v] == v)return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a,int b){
        a = find(a);
        b = find(b);

        if(a!=b){
            if(sz[a]<sz[b])swap(a,b);
            parent[b] =a;
            sz[a] += sz[b];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;

        DSU dsu(n);

        for(int i=0;i<n;i++){
            dsu.make(i);
        }

        int components = n;

        for(auto &v : connections) {

            int u = v[0];
            int w = v[1];

            if(dsu.find(u) != dsu.find(w)) {
                dsu.Union(u, w);
                components--;
            }
        }

        return components-1;
    }
};