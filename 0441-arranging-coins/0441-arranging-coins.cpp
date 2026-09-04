class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0, r = n;
        int ans  = 0;

        while(l<=r){
            long long mid = l + (r-l)/2;

            long long val = (mid+mid*mid)/2;

            if(val == n)return mid;
            if(val>n){
                r = mid-1;
            }else{
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
};