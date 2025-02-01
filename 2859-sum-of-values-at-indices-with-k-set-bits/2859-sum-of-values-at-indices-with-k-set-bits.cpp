class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            int x=i;
            while(x){
                if(x%2)cnt++;
                x/=2;
            }
            if(cnt==k){
                sum+=nums[i];
            }
        }
        return sum;
    }
};