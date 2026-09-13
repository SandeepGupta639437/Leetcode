class Solution {
public:
    void rotateLeft(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0)return ;
        k %= n;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
    // void rotateRight(vector<int>& nums, int k) {
    //     int m = nums.size();
    //     k %= m;
    //     reverse(nums.begin(), nums.end());
    //     reverse(nums.begin(), nums.begin() + k);
    //     reverse(nums.begin() + k, nums.end()); 
    // }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;i++){
            rotateLeft(grid[i],rowShift[i]);
        }

        for(int j=0;j<n;j++){
            vector<int>temp;
            for(int i=0;i<n;i++){
                temp.push_back(grid[i][j]);
            }
            rotateLeft(temp,colShift[j]);
            for(int i=0;i<n;i++){
                grid[i][j] = temp[i];
            }
        }

        return grid;
        
    }
};