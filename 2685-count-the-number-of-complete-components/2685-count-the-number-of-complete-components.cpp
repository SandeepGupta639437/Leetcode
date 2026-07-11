class Solution {
public:
    vector<int> parent,rnk;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);// Path compression
    }
    void Union(int x,int y){
        int parx=find(x);
        int pary=find(y);
        // Union by rank
        if(rnk[parx]>rnk[pary]) parent[pary]=parx;
        else if(rnk[parx]<rnk[pary]) parent[parx]=pary;
        else{
            parent[pary]=parx;
            rnk[parx]++;
        } 
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //  Initialize Union-Find
        parent.resize(n);
        rnk.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<vector<int>> adj(n);
        for(auto &ele: edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        for(auto &ele: edges){
            if(find(ele[0])!=find(ele[1])) Union(ele[0],ele[1]);
        }

        vector<int> help1(n,0),help2(n,0);
        for(int i=0;i<n;i++){
            help1[find(i)]++;
            help2[find(i)]+=adj[i].size();
        }
        int completeComp=0;
        for(int i=0;i<n;i++){
            if(find(i)==i and help1[i]*(help1[i]-1)==help2[i]) completeComp++;
        }
        return completeComp;
    }
};