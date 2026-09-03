class Solution {
public:
    bool check(int k,vector<int>& piles,int h){
        for(auto &it:piles){
            h -= (it+k-1)/k;
        }
        return (h>=0);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l= 1, r = 1e9+7;
        int ans = 0;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(mid,piles,h)){
                ans = mid;
                r = mid-1;
            }else {
                l = mid+1;
            }
        }

        return ans;
    }
};