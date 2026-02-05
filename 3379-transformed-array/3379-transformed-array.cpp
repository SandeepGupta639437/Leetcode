class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
           if(a[i]>0){
            ans[i]=a[(i+a[i])%n];
           }
           else if(a[i]<0){
             ans[i]=a[abs((n+i)+a[i]%n)%n];
           }
           else ans[i]=a[i];
        }
     return ans;
    }
};