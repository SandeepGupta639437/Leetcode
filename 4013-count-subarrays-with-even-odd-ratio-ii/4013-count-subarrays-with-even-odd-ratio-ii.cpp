class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int A, int B) {

        int n = nums.size();

        vector<long long> pref;

        int even = 0, odd = 0;

        // F(-1)
        pref.push_back(0);

        for (int x : nums) {
            if (x & 1)
                odd++;
            else
                even++;

            pref.push_back(1LL * B * even - 1LL * A * odd);
        }

        // Coordinate Compression
        vector<long long> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick bit(vals.size());

        long long ans = 0;

        for (long long x : pref) {

            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            // previous prefixes >= current
            ans += bit.query(vals.size()) - bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return ans;
    }
};