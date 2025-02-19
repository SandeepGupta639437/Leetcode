class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s = 0;
        int l = n - 1;
        int ans = 0;

        while (s < l) {
            // Calculate the area between the two lines
            ans = max(ans, min(height[s], height[l]) * (l - s));

            // Move the pointer pointing to the shorter line
            if (height[s] < height[l]) {
                s++;
            } else {
                l--;
            }
        }
        return ans;
    }
};
