class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i=0;i<n;i++){
            int temp = landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                if(temp>=waterStartTime[j])
                    ans = min(ans,temp+waterDuration[j]);
                else
                    ans = min(ans,waterStartTime[j]+waterDuration[j]);
            }
        }
        for(int i=0;i<m;i++){
            int temp = waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                if(temp>=landStartTime[j])
                    ans = min(ans,temp+landDuration[j]);
                else
                    ans = min(ans,landStartTime[j]+landDuration[j]);
            }
        }
        return ans;
    }
};