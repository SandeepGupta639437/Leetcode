class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int gcdOfOddEvenSums(int n) {
        long long sumEven=n*(n+1);
        long long sumOdd=n*n;  
        return gcd(sumEven,sumOdd);
    }
};