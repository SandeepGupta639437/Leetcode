class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int>>v;
        int n=costs.size();
        for(int i=0;i<n;i++){
            v.push_back({costs[i],capacity[i]});
        }
        sort(v.begin(),v.end());

        vector<int>mp(n);
        mp[0]=v[0].second;
        for(int i=1;i<n;i++){
             mp[i]=max(mp[i-1],v[i].second);
        }
        int ans=0;
         // one machine
        for (int i = 0; i < n; i++) {
            if (v[i].first < budget) {
                ans = max(ans, v[i].second);
            }
        }

        for (int r = 1; r < n; r++) {
            int remaining = budget -v[r].first;
            if (remaining <= 0) continue;

            int l = 0, h = r - 1, idx = -1;
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (v[mid].first < remaining) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }

            if (idx != -1) {
                ans = max(ans, mp[idx] + v[r].second);
            }
        }

        return ans;
    }
};