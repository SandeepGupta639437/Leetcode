class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string s = "";

        // extract digits
        while(n){
            int d = n % 10;
            sum += d;
            if(n%10) s += char('0' + d);
            n /= 10;
        }

        reverse(s.begin(), s.end());

        long long num = 0;
        for(char c : s){
            num = num * 10 + (c - '0');
        }

        return num * sum;
    }
};