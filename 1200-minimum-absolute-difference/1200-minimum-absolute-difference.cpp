class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minDif=INT_MAX;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            minDif=min(minDif,arr[i+1]-arr[i]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n-1;i++){
          if(arr[i+1]-arr[i]==minDif){
            ans.push_back(vector<int>{arr[i],arr[i+1]});
          }
        }
        return ans;
        
    }
};