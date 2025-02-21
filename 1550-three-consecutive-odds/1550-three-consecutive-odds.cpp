class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& nums) {
        int cnt=0;
       for(int i=0;i<nums.size();i++){
          if(nums[i]%2)cnt++;
          else cnt=0;
          if(cnt==3)return true;
       }
       return false;
    }
};