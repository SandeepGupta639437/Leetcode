class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        set<int> st(nums.begin(), nums.end());

        for (int it : st) {
            if (it < lower) continue;

            if (it > upper) break;

            if (it > lower) {
                ans.push_back({lower, it - 1});
            }
            lower = it + 1;
        }

        if (lower <= upper) {
            ans.push_back({lower, upper});
        }

        return ans;
    }
};