class Solution {
public:

    #define ll long long
    long long countCommas(long long n) {
        ll result = 0;
        ll start = 1e3;

        while(start<=n){
            result += (n-start+1);
            start *=1e3;
        }
        return result;
    }
};