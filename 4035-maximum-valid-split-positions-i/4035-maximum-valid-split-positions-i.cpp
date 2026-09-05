class Solution {
public:
    int solve(vector<int> &nums,int k,vector<int> &suffix,vector<int> &prefix){
        int n = nums.size();

        int removed ;

        // 1. Remove nums[k]
        if(k != -1) {
            removed = nums[k];
            nums.erase(nums.begin() + k);
        }

        int m = nums.size();

        if(m == 0) {
            nums.insert(nums.begin() + k, removed);
            return 0;
        }

        prefix.resize(m,0);
        suffix.resize(m,0);

        prefix[0] = nums[0];

        for(int i=1;i<m;i++){
            prefix[i] = __gcd(prefix[i-1],nums[i]);
        }

        suffix[m-1] = nums[m-1];
        for(int i=m-2;i>=0;i--){
            suffix[i] = __gcd(suffix[i+1],nums[i]);
        }

        int ans = 0;

        for(int i=0;i<m-1;i++){
            if(prefix[i]==suffix[i+1]){
                ans++;
            }
        }
        if(k != -1) {
            nums.insert(nums.begin() + k, removed);
        }
        return ans;
    }


    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();

        int ans = 0;
        vector<int>suffix;
        vector<int>prefix;
        vector<int> prefixmain(n, 0);
        prefixmain[0] = nums[0];
        for (int i=1;i<n;i++){
            prefixmain[i] = gcd(prefixmain[i-1],nums[i]);
        }
        // case1
        ans = solve(nums,-1,suffix,prefix); //no removal     O(n)

        for(int i=0;i<n;i++){
            if (i > 0 && prefixmain[i] == prefixmain[i - 1]) continue;
             // remove krne se koi fayda nhi hone wala 
            //ye number of solve calls ko bhut decrease krde rha hai
            int curr = solve(nums,i,suffix,prefix);
            ans = max(curr,ans);
        }

        return ans;
    }
};
