class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        int maxLength = 0;

        unordered_map<int,int> mp;

        int left = 0;

        for(int right = 0; right < n; right++) {

            mp[nums[right]]++;

            while(mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};