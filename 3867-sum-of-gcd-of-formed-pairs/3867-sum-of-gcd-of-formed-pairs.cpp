class Solution {
public:
    typedef long long ll;

    ll gcd(ll a,ll b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<ll>mx(n);
        vector<ll>prefGCD(n);
        mx[0]=nums[0];
        for(ll i=1;i<n;i++){
            ll maxi = max(mx[i-1],1LL*nums[i]);
            mx[i]=maxi;
        }
        for(ll i=0;i<n;i++){
            prefGCD[i]=gcd(mx[i],nums[i]);
        }
        sort(begin(prefGCD),end(prefGCD));
        ll l=0,r=n-1,ans=0;
        while(l<r){
           ans+=gcd(prefGCD[l],prefGCD[r]);
           l++;
           r--;
        }
        return ans;
    }
};