class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(int i, vector<int>& nums, vector<int>& temp) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }

        // Not take
        solve(i + 1, nums, temp);

        // Take
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }
};