class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        vector<long long> pref(n);
        pref[0] = tasks[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + tasks[i];

        vector<int> ans;

        int j = 0;                 // current task
        long long left = tasks[0]; // remaining work of current task

        for (long long s : shifts) {

            // Can't finish current task
            if (s < left) {
                left -= s;
                ans.push_back(n - j);
                continue;
            }

            // Finish current task
            s -= left;
            j++;

            // Finished everything
            if (j == n) {
                ans.push_back(0);
                j = 0;
                left = tasks[0];
                continue;
            }

            // Binary search from task j
            long long before = pref[j - 1];
            long long target = before + s;

            int l = j, r = n - 1;
            int last = j - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (pref[mid] <= target) {
                    last = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            j = last + 1;

            if (j == n) {
                ans.push_back(0);
                j = 0;
                left = tasks[0];
            } else {
                long long used = pref[j - 1] - before;
                left = tasks[j] - (s - used);
                ans.push_back(n - j);
            }
        }

        return ans;
    }
};