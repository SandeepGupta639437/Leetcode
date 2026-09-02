class DSU{
public:
    vector<int>parent;
    vector<int>sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n,1);

        for(int i=0;i<n;i++)parent[i]=i;
    }

    int find(int v){
        if(parent[v] ==v)return v;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int m = accounts.size();

        DSU ds(m);

        unordered_map<string,int> mapMailNode;

        for(int i=0;i<m;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }else{
                    ds.Union(i,mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[m];

        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.find(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0;i<m;i++){
            if(mergedMail[i].size()==0)continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());

            vector<string>temp;
            temp.push_back(accounts[i][0]);

            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};