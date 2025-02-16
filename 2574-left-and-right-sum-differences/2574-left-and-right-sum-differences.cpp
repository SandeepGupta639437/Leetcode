class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int s=0;
        int l=0;
        int n=nums.size();
        vector<int>a(n);
        for(int i=0;i<n;i++){
            l+=nums[i];
        }
        for(int i=0;i<n;i++){
           a[i]=abs(l-s-nums[i]);
           s+=nums[i];
           l-=nums[i];
        }
        return a;
    }
};