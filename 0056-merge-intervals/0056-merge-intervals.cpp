class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(begin(intervals),end(intervals),[](const vector<int>a,const vector<int>b){
            return a[0] < b[0];
        });

        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();
        int prev = 0;
        if(n==1)return ans;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ans[prev][1]){
                ans[prev][1] = max(intervals[i][1],ans[prev][1]);
            }else{
                ans.push_back(intervals[i]);
                prev++;
            }
        }
      return ans;
    }
};