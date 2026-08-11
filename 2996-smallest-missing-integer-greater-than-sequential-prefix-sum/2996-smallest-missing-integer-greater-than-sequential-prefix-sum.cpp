class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        int sum = nums[0];
        int n = nums.size();

        for(int i = 0; i + 1 < n; i++) {
            if(nums[i] + 1 == nums[i + 1])
                sum += nums[i + 1];
            else
                break;
        }

        unordered_set<int> st(nums.begin(), nums.end());

        for(int i = sum;;i++) {
            if(st.find(i) == st.end())
                return i;
        }
    }
};