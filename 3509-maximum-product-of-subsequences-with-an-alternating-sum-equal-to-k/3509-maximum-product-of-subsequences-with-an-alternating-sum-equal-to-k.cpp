class Solution {
public:
    // int dp[151][1800][5001][3];
    unordered_map<int,unordered_map<int ,unordered_map<int,unordered_map<int,int>>>> dp;
    int k,limit,n;
    int solve(int i,int currSum,int currProd,int type,vector<int> &v){
        if(i>=n){
            if(currSum==k && currProd<=limit && type!=0){
                return currProd;
            }
            return -1;
        }

        if(dp.count(i) && dp[i].count(currSum) && dp[i][currSum].count(currProd) && dp[i][currSum][currProd].count(type))return dp[i][currSum][currProd][type];
        // long long key = ( (long long)(currSum + 1000) << 14) | ((long long)currProd << 2) | type;

        // if (dp[i].count(key)) return dp[i][key];

        int ans = solve(i+1,currSum,currProd,type,v);

        if(type==0){
            ans = max( ans , solve(i+1,currSum+v[i],v[i],1,v) );
        }else if(type==1){
            ans = max( ans , solve(i+1,currSum-v[i],min(1LL*currProd*v[i], 1LL*limit+1),2,v) );
        }else if(type==2){
            ans = max( ans , solve(i+1,currSum+v[i],min(1LL*currProd*v[i], 1LL*limit+1),1,v) );
        }

        return dp[i][currSum][currProd][type] =  ans;
    }
    int maxProduct(vector<int>& nums, int K, int Limit) {
        k = K;
        limit = Limit;
        n = nums.size();
        //tghis optimisation helps to solve this question
        int sum = 0;
        for(auto &it:nums)sum+=it;

        if(k>sum || k< -sum)return -1;
        dp.clear();
        return solve(0,0,0,0,nums);
        
    }
};