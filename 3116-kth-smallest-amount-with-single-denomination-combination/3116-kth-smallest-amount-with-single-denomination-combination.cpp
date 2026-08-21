class Solution {
public:
    using ll = long long;
    long long maxi = 1e11;
    int k;

    // long long count(long long x, vector<int>& coins){
    //     long long cnt = 0;

    //     for(int it : coins){
    //         cnt += x/it;
    //     }

    //     return cnt;
    // }   /// it fails due to the similar value in different denominations counts multiple times
    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long cnt = 0;

        for (int mask = 1; mask < (1 << n); mask++) {

            long long l = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    l = lcm(l, (long long)coins[i]);

                    if (l > x)
                        break;
                }
            }

            if (l > x)
                continue;

            long long ways = x / l;

            if (bits % 2 == 1)
                cnt += ways;
            else
                cnt -= ways;
        }

        return cnt;
    }
    
    long long findKthSmallest(vector<int>& coins, int K) {
        k = K;
        long long low = 0;
        long long high = maxi;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (count(mid, coins) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};