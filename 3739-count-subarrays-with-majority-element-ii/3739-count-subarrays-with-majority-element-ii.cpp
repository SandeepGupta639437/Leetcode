class Solution {
public:
    typedef long long ll ;
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        ll cumSum = 0;
        map<int,int>mp;
        ll validLeft = 0;
        ll result = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validLeft += mp[cumSum];
                cumSum++;
            }
            else{
                cumSum--;
                validLeft -= mp[cumSum];
            }
            mp[cumSum]++;
            result+=validLeft;
        }
        return result;
    }
};