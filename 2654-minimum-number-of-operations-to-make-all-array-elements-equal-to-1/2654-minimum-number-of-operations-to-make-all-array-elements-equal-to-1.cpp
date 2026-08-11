class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        for(int x : nums) {
            if(x == 1)  cnt1++;
        }

        if(cnt1 > 0) return n - cnt1;

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {

            int left = INT_MAX;
            int right = INT_MAX;

            // Expand to right
            int gcdRight = nums[i];
            for(int j = i + 1; j < n; j++) {
                gcdRight = gcd(gcdRight, nums[j]);
                if(gcdRight == 1) {
                    right = j - i;
                    break;
                }
            }

            // Expand to left
            int gcdLeft = nums[i];
            for(int j = i - 1; j >= 0; j--) {
                gcdLeft = gcd(gcdLeft, nums[j]);
                if(gcdLeft == 1) {
                    left = i - j;
                    break;
                }
            }
            ans = min({ans, left, right});
        }

        if(ans == INT_MAX) return -1;

        return ans + n - 1;
    }
};