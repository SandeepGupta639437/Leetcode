class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(begin(nums),end(nums));
        int val = 1;
        while(val<=maxEl)val<<=1;

        vector<bool>s1(val,false),s2(val,false);

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i]^nums[j]] = true;
            }
        }

        for(int i=0;i<val;i++){
            if(s1[i]){
                for(int j=0;j<n;j++){
                    s2[i^nums[j]]=true;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<val;i++){
            if(s2[i])ans++;
        }
        return ans;
    }
};