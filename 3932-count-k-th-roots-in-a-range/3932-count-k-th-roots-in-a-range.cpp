class Solution {
public:

    long long power(long long a, int k, long long limit){

        long long res = 1;

        for(int i = 0; i < k; i++){

            if(a != 0 && res > limit / a)
                return limit + 1;

            res *= a;
        }

        return res;
    }

    int kthRoot(long long n, int k){

        if(n < 0)
            return -1;

        int low = 0, high = 1e9;
        int ans = 0;

        while(low <= high){

            long long mid = low + (high - low) / 2;

            if(power(mid, k, n) <= n){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    int countKthRoots(int l, int r, int k) {

        int right = kthRoot(r, k);

        int left = (l == 0) ? -1 : kthRoot((long long)l - 1, k);

        return right - left;
    }
};