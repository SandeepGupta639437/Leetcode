class Solution {
    // int n;
    // void dfs(unordered_map<int,vector<int>>&adj,int u, vector<bool> &visited ){
    //     visited[u]=true;
    //     for(int &v : adj[u]){
    //         if(!visited[v]){
    //             dfs(adj,v,visited);
    //         }
    //     }
    // }
public:
    int parent[205],size[205];
    void make(int v){
        parent[v] =v;
        size[v] =1;
    }

    int find(int v){
        if(parent[v]==v)return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            if(size[a]<size[b])swap(a,b);
            parent[b] = a;
            size[a]+=size[b];
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // n=isConnected.size();
        // vector<bool>visited(n,false);
        // unordered_map<int,vector<int>>adj;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(!visited[i]){
        //         dfs(adj,i,visited);
        //         cnt++;
        //     }
        // }
        int m = isConnected.size();
        int n = isConnected[0].size();
        for(int i = 1; i <= m; i++){
            make(i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    Union(i+1,j+1);
                }
            }
        } 
        int cnt =0;
        for(int i=1;i<=m;i++){
            if(parent[i]==i)cnt++;
        }
      return cnt;
    }
};