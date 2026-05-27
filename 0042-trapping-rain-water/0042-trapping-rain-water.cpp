class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> prefMax(n);
        vector<int> suffMax(n);

        // Prefix max
        prefMax[0] = 0;

        for(int i = 1; i < n; i++){
            prefMax[i] = max(prefMax[i-1], height[i-1]);
        }

        // Suffix max
        suffMax[n-1] = 0;

        for(int i = n-2; i >= 0; i--){
            suffMax[i] = max(suffMax[i+1], height[i+1]);
        }

        int water = 0;

        for(int i = 0; i < n; i++){

            int leftMax = prefMax[i];
            int rightMax = suffMax[i];

            int mn = min(leftMax, rightMax);

            if(mn > height[i]){
                water += mn - height[i];
            }
        }

        return water;
    }
};