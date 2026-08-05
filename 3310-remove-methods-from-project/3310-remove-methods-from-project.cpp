class Solution {
public:
    vector<int>ans;
    vector<bool>visited;
    void dfs(int node,vector<vector<int>>& nums){
        visited[node] = true;
        for(auto it:nums[node]){
           if(!visited[it]) dfs(it,nums);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> nums(n);
        visited.resize(n,false);
        for(auto it : invocations){
            nums[it[0]].push_back(it[1]);
        }
        dfs(k,nums);
        
        for(auto it : invocations){
            if(!visited[it[0]] && visited[it[1]]){
                for(int i=0;i<n;i++)ans.push_back(i);
                return ans;
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i])ans.push_back(i);
        }
        return ans;

    }
};