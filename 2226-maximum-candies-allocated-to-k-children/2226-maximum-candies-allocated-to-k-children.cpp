class Solution {
public:
    long long count(int candy ,vector<int> &candies){
        int n = candies.size();
        long long y = 0;
        for(int i=0;i<n;i++){
            y += (candies[i])/candy;
        }
        return y;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(begin(candies),end(candies));
        int ans = 0;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(count(mid,candies) >= k){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};