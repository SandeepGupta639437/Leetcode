class Solution {
public:
    int largestRectangle(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : nums[i];

            while (!st.empty() && nums[st.top()] > currHeight) {
                int h = nums[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, h * width);
            }

            st.push(i);
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