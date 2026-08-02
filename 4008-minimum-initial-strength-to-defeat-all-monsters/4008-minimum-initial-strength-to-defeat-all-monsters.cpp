class Solution {
public:
    int n;
    bool valid(long long strength,vector<int>& monsters,vector<long long>& bonus) {

        for (int i = 0; i < n; i++) {
            if (strength + bonus[i] < monsters[i]) return false;
            strength -= monsters[i];
            if (strength < 0)  strength = 0;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        long long r = accumulate(begin(monsters),end(monsters),0LL);
        n = monsters.size();

        vector<long long>prefBoost(n+1,0);
        for(auto& v:boosts){
            prefBoost[v[0]]+=v[2];
            prefBoost[v[1]+1]-=v[2];
        }
        for(int i=1;i<=n;i++){
            prefBoost[i] += prefBoost[i-1];
        }
        long long l = 0;
        int ans = 0;
        while(l<r){
            long long mid =  l + (r-l)/2;
            if(valid(mid,monsters,prefBoost)){
                r =  mid;
            }else{
                l  = mid+1;
            }
        }
        return l;
    }
};