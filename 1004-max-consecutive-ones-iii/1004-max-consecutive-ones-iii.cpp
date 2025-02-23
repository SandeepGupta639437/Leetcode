class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, maxlen = 0;
        int cnt0 = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) cnt0++;
            // Shrink the window if zero count exceeds k
            while (cnt0 > k) {
                if (nums[l] == 0) cnt0--;
                l++;
            }
            // Update maxlen with the current valid window size
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
