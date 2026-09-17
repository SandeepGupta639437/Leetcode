class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLenTillIdx(n + 1, INT_MAX);

        int l = 0,r=0;
        int sum = 0;
        int ans = INT_MAX;

       while(r<n){
            sum += arr[r];

            while (l<r && sum > target) {
                sum -= arr[l];
                l++;
            }

            minLenTillIdx[r + 1] = minLenTillIdx[r];

            if (sum == target) {
                int len = r - l + 1;

                if (minLenTillIdx[l] != INT_MAX) {
                    ans = min(ans, len + minLenTillIdx[l]);
                }

                minLenTillIdx[r+1] = min(minLenTillIdx[r+1], len);
            }
            r++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};