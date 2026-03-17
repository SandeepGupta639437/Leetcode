class Solution {
public:
    string word1,word2;
    int dp[501][501];

    int solve(int i, int j){
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;

        if(dp[i][j] != -1) return dp[i][j];

        int x=0,y=0,z=0;
        // delete from word1
        x = 1 + solve(i+1,j);
        // insert into word1
        y = 1 + solve(i,j+1);
        // replace or match
        if(word1[i] != word2[j])z = 1 + solve(i+1,j+1);
        else z = solve(i+1,j+1);

        return dp[i][j] = min({x,y,z});
    }

    int minDistance(string word1_, string word2_) {
        word1 = word1_;
        word2 = word2_;
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};