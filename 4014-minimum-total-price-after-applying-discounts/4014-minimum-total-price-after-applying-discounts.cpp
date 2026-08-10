class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(begin(prices),end(prices),greater<int>());
        sort(begin(discounts),end(discounts),greater<int>());
        int m = discounts.size();
        int n = prices.size();
        double ans = 0;
        int i=0;
        for(i=0;i<m && i<n;i++){
            ans+= prices[i] - ((double)prices[i]/100.0)*discounts[i];
        }
        while(i<n){
            ans+=prices[i];
            i++;
        }
        return ans;
    }
};