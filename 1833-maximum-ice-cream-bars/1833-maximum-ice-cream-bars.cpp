class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = *max_element(costs.begin(), costs.end());
        vector<int>mp(maxi+1,0);
        for(auto it : costs){
            mp[it]++;
        }
        int ans = 0;
        for(int i = 1;i<=maxi;i++){
            if(i>coins)return ans;
            if(1LL*mp[i]*i <= coins){
                coins-=mp[i]*i;
                ans += mp[i];
            }else{
                int l = 1, r = mp[i];
                int ansT = 0;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    if(1LL*mid*i <= coins){
                        l = mid+1;
                        ansT = max(ansT,mid);
                    }else if (1LL*mid*i>coins){
                        r = mid-1;
                    }else{
                        return ans+mid;
                    }
                }
                return ans+ansT;
            }
        }
        return ans;
    }
};