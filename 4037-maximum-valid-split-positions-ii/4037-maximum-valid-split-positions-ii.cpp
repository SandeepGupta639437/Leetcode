class Solution {
public:
    int solve(vector<int> &nums,int k){
        int n = nums.size();

        vector<int>arr;
        for(int i=0;i<n;i++){
            if(k!=i)arr.push_back(nums[i]);
        }

        int m = arr.size();

        if(m == 0) return 0;

        vector<int>prefix(m,0);
        vector<int>suffix(m,0);

        prefix[0] = arr[0];

        for(int i=1;i<m;i++){
            prefix[i] = __gcd(prefix[i-1],arr[i]);
        }

        suffix[m-1] = arr[m-1];
        for(int i=m-2;i>=0;i--){
            suffix[i] = __gcd(suffix[i+1],arr[i]);
        }

        int ans = 0;

        for(int i=0;i<m-1;i++){
            if(prefix[i]==suffix[i+1]){
                ans++;
            }
        }
        return ans;
    }

    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();

        int ans = 0;
        vector<int> prefixmain(n, 0);
        prefixmain[0] = nums[0];
        for (int i=1;i<n;i++){
            prefixmain[i] = gcd(prefixmain[i-1],nums[i]);
        }
        // case1
        ans = solve(nums,-1); //no removal

        for(int i=0;i<n;i++){
            if (i > 0 && prefixmain[i] == prefixmain[i - 1]) continue;
             // remove krne se koi fayda nhi hone wala 
            //ye number of solve calls ko bhut decrease krde rha hai
            int curr = solve(nums,i);
            ans = max(curr,ans);
        }

        return ans;
    }
};
