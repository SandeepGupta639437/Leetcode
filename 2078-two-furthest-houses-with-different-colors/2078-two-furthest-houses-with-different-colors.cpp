class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int x1 = colors[n-1];
        int x2  = colors[0];
        int ans = 0;
        for(int i=0;i<n;i++){
          if(colors[i]!=x1)ans=max(ans,abs(n-1-i));
        }
        for(int i=n-1;i>=0;i--){
          if(colors[i]!=x1)ans=max(ans,i);
        }
        return ans;
    }
};