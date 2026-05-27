class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        map<pair<int,int>,int>mpp;
        for(int i=0;i<n;i++){
            int val1 = dominoes[i][0];
            int val2 = dominoes[i][1];
            if(val1<=val2){
                mpp[{val1,val2}]++;
            }else{
                mpp[{val2,val1}]++;
            }
        }
        int ans = 0;
        for(auto mp:mpp){
            int x = mp.second;
            if(x%2){
                int temp = 1;
                temp *= (x-1)/2;
                temp *=x;
                ans += temp;
            }else{
                int temp = 1;
                temp *= (x)/2;
                temp *=(x-1);
                ans += temp;
            }
        }
        return ans;
    }
};