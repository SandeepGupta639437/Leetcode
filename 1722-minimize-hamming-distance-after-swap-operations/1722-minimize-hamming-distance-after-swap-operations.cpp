class Solution {
public:
    vector<int> parent, size;

    void make(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++) make(i);

        for(auto &e : allowedSwaps){
            Union(e[0], e[1]);
        }

        unordered_map<int, unordered_map<int,int>> mp;

        // Count frequencies of source values in each component
        for(int i = 0; i < n; i++){
            int p = find(i);
            mp[p][source[i]]++;
        }

        int ans = 0;

        // Match target values
        for(int i = 0; i < n; i++){
            int p = find(i);
            if(mp[p][target[i]] > 0){
                mp[p][target[i]]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};