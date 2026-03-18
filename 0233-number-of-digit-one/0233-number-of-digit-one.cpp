class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;

        for(long long div = 1; div <= n; div *= 10){
            long long high = n / (div * 10);
            long long cur  = (n / div) % 10;
            long long low  = n % div;

            if(cur == 0){
                ans += high * div;
            }
            else if(cur == 1){
                ans += high * div + (low + 1);
            }
            else{
                ans += (high + 1) * div;
            }
        }

        return ans;
    }
};