class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans = 0;
        while(true){
            if(n>k){
                ans+=1LL*k*(n-k);
                n-=k;
            }
            if(m>k){
                ans+=1LL*k*(m-k);
                m-=k;
            }
            if(m<=k && n<=k){
                break;
            }
        }
        return ans;
    }
};