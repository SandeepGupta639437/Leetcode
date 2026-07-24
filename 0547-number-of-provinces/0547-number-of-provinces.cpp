class DSU{
    public:
       vector<int>parent;
       vector<int>size;
       DSU(int n){
         parent.resize(n);
         size.resize(n);
       }

       void make(int v){
         parent[v] = v;
         size[v] = 1;
       }

       int find(int v){
         if(parent[v] == v)return v;
         return parent[v] = find(parent[v]);
       }

       void Union(int a,int b){
          a = find(a);
          b = find(b);
          if(a!=b){
            if(size[a]<size[b])swap(a,b);
            parent[b] = a;
            size[a] += size[b];
          }
       }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        DSU c(n + 1);
        for(int i = 1; i <= m; i++){
            c.make(i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    c.Union(i+1,j+1);
                }
            }
        } 
        int cnt =0;
        for(int i=1;i<=m;i++){
            if(c.parent[i]==i)cnt++;
        }
      return cnt;
    }
};