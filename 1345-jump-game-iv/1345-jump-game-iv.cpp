class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> vis(n, 0);

        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0] = 1;

        while(!q.empty()) {

            auto [idx, steps] = q.front();
            q.pop();

            if(idx == n - 1)
                return steps;

            if(idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = 1;
                q.push({idx - 1, steps + 1});
            }

            if(idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = 1;
                q.push({idx + 1, steps + 1});
            }

            for(int next : mp[arr[idx]]) {
                if(!vis[next]) {
                    vis[next] = 1;
                    q.push({next, steps + 1});
                }
            }

            mp[arr[idx]].clear(); // important optimization
        }

        return -1;
    }
};