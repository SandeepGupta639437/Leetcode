class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        int i=0,j=0;
        int cnt = 1;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        vector<vector<int>>ans;
        set<pair<int,int>> vis;
        vis.insert({0,0});
        while(cnt<=k){
            auto [sum, p] = pq.top();
            auto [y,z] = p;
            pq.pop();
            cnt++;
            ans.push_back({nums1[y],nums2[z]});
            if (y+1 < nums1.size() && !vis.count({y+1,z})) {
                vis.insert({y+1,z});
                pq.push({nums1[y+1] + nums2[z], {y+1,z}});
            }

            if (z+1 < nums2.size() && !vis.count({y,z+1})) {
                vis.insert({y,z+1});
                pq.push({nums1[y] + nums2[z+1], {y,z+1}});
            }
        }
        return ans;
    }
};