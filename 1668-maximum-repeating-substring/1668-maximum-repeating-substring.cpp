class Solution {
public:
    int maxRepeating(string sequence, string word) {

        int n = sequence.size();
        int m = word.size();

        vector<int> dp(n,0);

        int ans = 0;

        for(int i=m-1;i<n;i++){

            if(sequence.substr(i-m+1,m)==word){

                dp[i]=1;

                if(i>=m)
                    dp[i]+=dp[i-m];

                ans=max(ans,dp[i]);
            }
        }

        return ans;
    }
};