class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int maxi = 1;
        sort(arr.begin(),arr.end());
        if(arr[0]!=1){
            arr[0]=1;
            maxi=arr[0];
        }
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])<=1){
                maxi = max(arr[i],arr[i-1]);
            }else{
                arr[i] = arr[i-1]+1;
                maxi = arr[i];
            }
        }
        return maxi;
    }
};