class Solution {
public:
    int parent[100005], sz[100005];

    void make(int v){
        parent[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a,int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums,int maxDiff,vector<vector<int>>& queries) {

        for(int i = 0; i < n; i++)
            make(i);

        // Build connected components
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] <= maxDiff)
                Union(i, i-1);
        }

        vector<bool> ans;

        for(auto &q : queries){
            ans.push_back(find(q[0]) == find(q[1]));
        }

        return ans;
    }
};