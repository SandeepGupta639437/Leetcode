class Solution {
public:
    typedef long long ll;
    ll gcd(ll a,ll b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            nums[i]=gcd(mx,nums[i]);
        }
        sort(begin(nums),end(nums));
        ll l=0,r=n-1,ans=0;
        while(l<r){
           ans+=gcd(nums[l],nums[r]);
           l++;
           r--;
        }
        return ans;
    }
};