class DSU{
public:
    vector<int>parent;
    vector<int>sz;

    DSU(int n){
        parent.resize(n);
        sz.resize(n,1);

        for(int i=0;i<n;i++)parent[i] = i;
    }

    int find(int v){
        if(parent[v]==v)return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a,int b){
        a = find(a);
        b = find(b);

        if(a==b)return;

        if(sz[a]<sz[b])swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{0,1},{1,0},{-1,0},{0,-1}};

    int id(int x,int y){
        return (m*x)+y;
    }

    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        DSU ds(m*n);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto &dir : directions){
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];

                        if(new_i>=0 && new_i<m && new_j>=0 && new_j<n){
                            if(grid[new_i][new_j]==1){
                                ds.Union(id(i,j),id(new_i,new_j));
                            }
                        } 
                    }
                }
            }
        }

        int ans = 0;

        for(int i=0;i<m*n;i++){
            ans = max(ans,ds.sz[i]);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1)continue;

                set<int>components;

                for(auto &dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n){
                        if(grid[new_i][new_j]==1){
                            components.insert(ds.find(id(new_i,new_j)));
                        }
                    } 
                }

                int totalArea = 0;

                for(int it:components){
                    totalArea += ds.sz[it];
                }
                totalArea++;

                ans = max(ans,totalArea);
            }
        }
        return ans;
    }
};