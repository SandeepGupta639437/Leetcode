class Solution {
public:
    int digSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({{digSum(nums[i]), nums[i]}, i});
        }

        sort(v.begin(), v.end());

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[v[i].second] = i;
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            while (p[i] != i) {
                swap(p[i], p[p[i]]);
                cnt++;
            }
        }

        return cnt;
    }
};