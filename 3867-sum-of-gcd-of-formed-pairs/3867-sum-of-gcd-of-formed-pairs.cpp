class Solution {
public:
    typedef long long ll;

    ll gcd(ll a,ll b){
        if(b==0) return a;
        return gcd(b,a%b);
    }

    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<ll> mx(n);
        mx[0] = nums[0];

        for(int i=1;i<n;i++)
            mx[i] = max(mx[i-1], (ll)nums[i]);

        vector<ll> prefGCD(n);

        for(int i=0;i<n;i++)
            prefGCD[i] = gcd(mx[i], nums[i]);

        map<ll,ll> freq;

        for(ll x : prefGCD)
            freq[x]++;

        vector<ll> vals;
        for(auto &p:freq)
            vals.push_back(p.first);

        ll l=0,r=vals.size()-1,ans=0;

        while(l<=r){

            ll a=vals[l], b=vals[r];

            if(l==r){
                ll cnt=freq[a]/2;
                ans+=cnt*gcd(a,a);
                break;
            }

            ll pairs=min(freq[a],freq[b]);

            ans+=pairs*gcd(a,b);

            freq[a]-=pairs;
            freq[b]-=pairs;

            if(freq[a]==0) l++;
            if(freq[b]==0) r--;
        }

        return ans;
    }
};