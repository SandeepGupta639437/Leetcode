class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // exact[g] = number of pairs whose gcd is exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            // count numbers divisible by g
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

            long long pairs = cnt * (cnt - 1) / 2;

            // subtract multiples
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                pairs -= exact[multiple];

            exact[g] = pairs;
        }

        // prefix[i] = total pairs having gcd <= i
        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {

            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1)
                    - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }
};