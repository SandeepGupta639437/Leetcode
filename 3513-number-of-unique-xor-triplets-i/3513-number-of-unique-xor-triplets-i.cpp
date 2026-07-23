class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Find the smallest power of 2 greater than n
        int p = 1;
        while (p <= n)
            p <<= 1;

        return p;
    }
};