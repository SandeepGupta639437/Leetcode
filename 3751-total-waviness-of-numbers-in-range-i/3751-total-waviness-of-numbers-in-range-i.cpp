class Solution {
public:
    int waviness(int n) {
        if (n < 100) return 0;
        int cnt = 0;
        int r = n % 10;n /= 10;
        int m = n % 10;n /= 10;
        while (n) {
            int l = n % 10;
            if ((m > l && m > r) || (m < l && m < r))cnt++;
            r = m;
            m = l;
            n /= 10;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1;i<=num2;i++){
            ans+=waviness(i);
        }
        return ans;
    }
};