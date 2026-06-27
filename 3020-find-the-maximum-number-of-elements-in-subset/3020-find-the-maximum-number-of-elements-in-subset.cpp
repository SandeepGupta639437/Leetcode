class Solution {
public:
    int solve(int x,map<int,int>& mp){
        int ans = 0;
        while(true){
            if(mp[x]>=2)ans+=2;
            else if(mp[x]==1)return ans+1;
            else return ans-1;
            x=1LL*x*x;
        }
    }
    int maximumLength(vector<int>& nums) {
        map<int,int>mpp;
        for(int it:nums){
            mpp[it]++;
        }

        int ans = (mpp[1]%2)?mpp[1]:mpp[1]-1;

        for(auto [x,y]:mpp){
            if(x!=1)ans = max(ans,solve(x,mpp));
        }
        return ans;
    }
};