class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            int cntEven = 0, cntOdd = 0;
            set<int> s;

            for (int j = i; j < n; j++) {
                if (s.find(nums[j]) == s.end()) {
                    if (nums[j] % 2) cntOdd++;
                    else cntEven++;
                    s.insert(nums[j]);
                }

                if (cntOdd == cntEven) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
