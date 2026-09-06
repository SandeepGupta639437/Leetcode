class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
         vector<long long>prefix;
        for(int &it:nums)prefix.push_back(it);
        for(int &it:nums)prefix.push_back(it);

        int n = nums.size();
        int m = prefix.size();

        for(int i=1;i<m;i++)prefix[i] += prefix[i-1]; 

        int ans = 0;
       
        for (int i = 0; i < n; i++) {
            int mid = i + n / 2 - 1;
            int end = i + n - 1;

            long long sum1 = prefix[mid] - (i > 0 ? prefix[i - 1] : 0);
            long long sum2 = prefix[end] - prefix[mid];

            if (sum1 > sum2) {
                ans++;
            }
        }
        return ans;
    }
};