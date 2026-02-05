class Solution {
public:
    
    int t[301][11];

    int solve(vector<int>&jd,int n,int idx,int d){
        if(d==1){
            int maxJD=jd[idx];
            for(int i=idx;i<n;i++){
                maxJD=max(maxJD,jd[i]);
            }
            return maxJD;
        }

        int maxJD=jd[idx];
        int finalResult=INT_MAX;
        if(t[idx][d]!=-1)return t[idx][d];

        for(int i=idx;i<=n-d;i++){
            maxJD=max(maxJD,jd[i]);
            int result= maxJD+solve(jd,n,i+1,d-1);
            finalResult=min(finalResult,result);
        }
        return t[idx][d]=finalResult;
    }

    int minDifficulty(vector<int>& jd, int d) {
       int n=jd.size();
       if(n<d)return -1;
       memset(t, -1, sizeof(t));
       return solve(jd,n,0,d);
        
    }
};