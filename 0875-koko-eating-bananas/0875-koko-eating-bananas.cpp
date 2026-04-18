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
         int low=0;
         int high=1e9;
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

