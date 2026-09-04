class Solution {
public:

    long long fact[11] = {
        1, 1, 2, 6, 24, 120,
        720, 5040, 40320, 362880, 3628800
    };

    long long makePalindrome(int x, int n) {

        long long result = x;

        int y = (n % 2) ? x / 10 : x;

        while (y) {
            result = result * 10 + y % 10;
            y /= 10;
        }

        return result;
    }

    long long countWays(long long num, int n) {

        int freq[10] = {};

        // Get digit frequency
        for (int i = 0; i < n; i++) {
            freq[num % 10]++;
            num /= 10;
        }

        // Total unique permutations
        long long total = fact[n];

        for (int d = 0; d < 10; d++)
            total /= fact[freq[d]];

        // Remove permutations starting with 0
        if (freq[0] > 0) {

            long long invalid = fact[n - 1];

            invalid /= fact[freq[0] - 1];

            for (int d = 1; d < 10; d++)
                invalid /= fact[freq[d]];

            total -= invalid;
        }

        return total;
    }

    long long countGoodIntegers(int n, int k) {

        int half = (n + 1) / 2;

        int start = 1;

        for (int i = 1; i < half; i++) start *= 10;

        int end = start * 10;

        long long ans = 0;

        unordered_set<long long> seen;

        for (int x = start; x < end; x++) {

            long long pal = makePalindrome(x, n);

            if (pal % k != 0) continue;

            // Encode frequency of digits
            int freq[10] = {};
            long long temp = pal;

            for (int i = 0; i < n; i++) {
                freq[temp % 10]++;
                temp /= 10;
            }

            // Encode frequency array into one number
            long long key = 0;

            for (int d = 0; d < 10; d++) {
                key = key * 13 + freq[d];
            }

            if (seen.count(key)) continue;

            seen.insert(key);

            ans += countWays(pal, n);
        }

        return ans;
    }
};