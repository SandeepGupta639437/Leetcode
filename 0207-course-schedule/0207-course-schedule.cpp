class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(auto it:prerequisites){
            int course = it[0];
            int preReq = it[1];
            adj[preReq].push_back(course);
            indegree[course]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for(auto it:adj[u]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(ans.size()==n)return true;
        return false;
    }
};