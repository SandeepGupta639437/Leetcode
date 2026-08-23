class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = target.size();
        for (int i = 0; i < n; i++) {
            target[i] = target[i] - nums[i];
        }

        long long ans = 0;
        long long ops = 0;
        int pos = (target[0] >= 0) ? 1 : 0;

        for (int i = 0; i < n; i++) {

            // Direction changed
            if ((target[i] < 0 && pos) ||
                (target[i] >= 0 && !pos)) {

                ans += abs(target[i]);

                pos = !pos;
                ops = abs(target[i]);

                continue;
            }

            if (abs((long long)target[i]) > ops) {
                ans += abs((long long)target[i]) - ops;
                ops = abs((long long)target[i]);
            }
            else {
                ops = abs((long long)target[i]);
            }
        }

        return ans;
    }
};