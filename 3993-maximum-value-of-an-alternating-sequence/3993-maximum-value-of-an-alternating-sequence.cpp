class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans = 0;
        if(n%2==0){
            int x = (n-2)/2;
            ans = 1LL*x*(m-1);
            ans += m;   
        }else{
            int x = (n-1)/2;
            ans = 1LL*x*(m-1);
            if(n>1)ans++;
        }
        return ans+s;
    }
};