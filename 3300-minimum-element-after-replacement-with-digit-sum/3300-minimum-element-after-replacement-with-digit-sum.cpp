class Solution {
public:
    int digitSum(int n){
        int temp = 0;
        while(n>0){
            int d = n%10;
            temp += d;
            n/=10;
        }
        return temp;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,digitSum(nums[i]));
        }
        return ans;
    }
};