class Solution {
public:
    bool check(int mid,vector<int>& piles,int h){
        double totalH = 0;
            for (auto it:piles) {
              totalH += ceil((double)(it) / (double)(mid));
            }
            if (totalH <= h) {
                return true;
            }
            return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
          int maxi = INT_MIN;
          int n = piles.size();
           //find the maximum:
          for (int i = 0; i < n; i++) {
             maxi = max(maxi, piles[i]);
           }
         int low=0;
         int high=maxi;
        while (low<=high) {
            int mid=(low+high)/2;
            if (check(mid,piles,h)) {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

