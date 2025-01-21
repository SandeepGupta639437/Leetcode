class Solution {
public:
    int minPartitions(string n) {
        int m=n.size();
        int i=0;
        int j=m-1;
        int ans=0;
        while(i<=j){
             ans=max(ans,n[i]-'0');
             ans=max(ans,n[j]-'0');
             i++;
             j--;
        }
        return ans;
    }
};