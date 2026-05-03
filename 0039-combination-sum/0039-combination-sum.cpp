class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& candidates, int target, int i, int sum, vector<int>& comb) {
        if (sum > target || i >= n) return;

        if (sum == target) {
            ans.push_back(comb);
            return;
        }

        // Pick current element (stay at same index)
        comb.push_back(candidates[i]);
        solve(candidates, target, i, sum + candidates[i], comb);
        comb.pop_back();

        // Skip current element (move to next index)
        solve(candidates, target, i + 1, sum, comb);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        n = candidates.size();
        solve(candidates, target, 0, 0, comb);
        return ans;
    }
};