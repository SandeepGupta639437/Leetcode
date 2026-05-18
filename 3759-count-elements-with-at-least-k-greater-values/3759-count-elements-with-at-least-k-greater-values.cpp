class Solution {
public:

    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(k == 0)
            return n;

        int ans = 0;
        int i = 0;
        while(i < n){
            int j = i;
            // same elements group
            while(j < n && nums[j] == nums[i]){
                j++;
            }
            // greater elements count
            int greater = n - j;
            // frequency of current number
            int freq = j - i;
            if(greater >= k)
                ans += freq;
            i = j;
        }
        return ans;
    }
};