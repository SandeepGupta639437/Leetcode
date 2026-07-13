class Solution {
public:
    bool valid(int cap,vector<int>& weights, int days){
        int cnt = 1;
        int n = weights.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += weights[i];
            if(sum>cap){
                cnt++;
                sum = weights[i];
            }
        }
        return (cnt<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = *max_element(weights.begin(), weights.end());
        int l = accumulate(weights.begin(), weights.end(), 0);
        int ans = INT_MAX;
        while(s<=l){
            int mid = (s+(l-s)/2);
            if(valid(mid,weights,days)){
                l = mid-1;
                ans = min(ans,mid);
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};