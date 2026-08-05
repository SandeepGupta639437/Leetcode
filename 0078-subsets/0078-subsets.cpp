class Solution {
public:
    set<vector<int>> st;
    int n;

    void solve(int i, vector<int>& arr, vector<int>& temp) {
        if (i == n) {
            st.insert(temp);
            return;
        }

        // Don't take arr[i]
        solve(i + 1, arr, temp);

        // Take arr[i]
        temp.push_back(arr[i]);
        solve(i + 1, arr, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(0, nums, temp);

        return vector<vector<int>>(st.begin(), st.end());
    }
};