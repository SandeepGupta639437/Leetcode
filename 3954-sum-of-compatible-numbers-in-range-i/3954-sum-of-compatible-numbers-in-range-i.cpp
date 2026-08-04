class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        int L = max(1, n - k);
        int R = n + k;

        for (int x = L; x <= R; x++) {
            if ((n & x) == 0)
                ans += x;
        }
        return ans;
    }
};