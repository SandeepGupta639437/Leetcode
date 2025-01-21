class Solution {
public:
    int minPartitions(string n) {
        int m=n.size();
        int ans=0;
        for(int i=0;i<m;i++){
             ans=max(ans,n[i]-'0');
        }
        return ans;
    }
};