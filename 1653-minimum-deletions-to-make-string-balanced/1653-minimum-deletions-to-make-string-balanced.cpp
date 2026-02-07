class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int cnta=0,cntb=0,ta=0,tb=0, ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(s[i]=='a')ta++;
        }
        tb=n-ta;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                cnta++;
                ans=min(ans,ta-cnta+cntb);
            }
            if(s[i]=='b'){
                ans=min(ans,ta-cnta+cntb);
                cntb++;
            }
        }
        if(n==1)return 0;
        return ans;
    }
};