class Solution {
public:
    int largestRectangle(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            ans = max(ans, nums[i] * width);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows =  matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> height(rows, vector<int>(cols, 0));

        for (int j = 0; j < cols; j++) {
            height[0][j] = matrix[0][j] - '0';

            for (int i = 1; i < rows; i++) {
                if (matrix[i][j] == '1')
                    height[i][j] = height[i - 1][j] + 1;
                else
                    height[i][j] = 0;
            }
        }

        int ans = 0;

        for (int i = 0; i < rows; i++) {
            ans = max(ans, largestRectangle(height[i]));
        }

        return ans;
    }
};