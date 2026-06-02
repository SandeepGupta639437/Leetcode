class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        // vector<int>finishland(n);
        // vector<int>finishWater(m);
        int finishlandMin = INT_MAX;
        int finishwaterMin = INT_MAX;
        for(int i=0;i<n;i++){
            finishlandMin = min(finishlandMin,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            finishwaterMin = min(finishwaterMin,waterStartTime[i]+waterDuration[i]);
        }
        int temp = finishlandMin;
        for(int j=0;j<m;j++){
            if(temp>=waterStartTime[j])
                ans = min(ans,temp+waterDuration[j]);
            else
                ans = min(ans,waterStartTime[j]+waterDuration[j]);
        }
        temp = finishwaterMin;
        for(int j=0;j<n;j++){
            if(temp>=landStartTime[j])
                ans = min(ans,temp+landDuration[j]);
            else
                ans = min(ans,landStartTime[j]+landDuration[j]);
        }
        return ans;
    }
};