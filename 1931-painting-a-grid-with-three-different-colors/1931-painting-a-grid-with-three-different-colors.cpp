class Solution {
public:
    vector<string>states;
    int m ;

    void generateStates(string currState,int l,char prevColor){
        if(l==m){
            states.push_back(currState);
            return;
        }

        for(char ch : {'R','G','B'}){
            if(ch==prevColor)continue;
            generateStates(currState+ch,l+1,ch);
        }
    }

    int MOD = 1e9+7;
    vector<vector<int>>dp;

    int solve(int n,int prev){
        if(n==0)return 1;

        int result = 0;

        if(dp[n][prev]!=-1)return dp[n][prev];

        string last = states[prev];

        for(int curr=0;curr<states.size();curr++){
            if(curr == prev)continue;

            bool conflict = false;
            string currPat = states[curr];

            for(int i=0;i<m;i++){
                if(currPat[i]==last[i]){
                    conflict = true;
                    break;
                }
            }

            if(!conflict){
                result = (result + solve(n-1,curr))%MOD;
            }
        }

        return dp[n][prev] = result;
    }

    int colorTheGrid(int M, int n) {
        int result = 0;
        m = M;
        generateStates("", 0, '#');
        int statesSize = states.size();

        dp.resize(n, vector<int>(statesSize, -1));

        for(int i=0;i<statesSize;i++){
            result = (result + solve(n-1,i))%MOD;
        }

        return result;

    }
};