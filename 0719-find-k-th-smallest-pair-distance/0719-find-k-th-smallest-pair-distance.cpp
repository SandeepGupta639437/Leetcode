class Solution {
public:
    bool check(int mid,vector<int>& nums,int k){
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            auto it = upper_bound(nums.begin(),nums.end(),nums[i]+mid);

            it--;
            int index = it - nums.begin();

            count += (index - i);

            if(count>=k)return true;

        }
        return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int low=0;
        int high=1e9;
        sort(nums.begin(),nums.end());
        while (low<=high) {
            int mid=(low+high)/2;
            if (check(mid,nums,k)) {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};