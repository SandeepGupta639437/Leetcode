class Solution {
public:

    vector<int> segTree;
    static const int MAXX = 50000;

    void update(int idx, int val, int i, int l, int r) {

        if (l == r) {
            segTree[i] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(idx, val, 2 * i + 1, l, mid);
        else
            update(idx, val, 2 * i + 2, mid + 1, r);

        segTree[i] = max(
            segTree[2 * i + 1],
            segTree[2 * i + 2]
        );
    }

    int queryMax(int start, int end,
                 int i, int l, int r) {

        if (l > end || r < start)
            return 0;

        if (start <= l && r <= end)
            return segTree[i];

        int mid = (l + r) / 2;

        return max(
            queryMax(start, end, 2 * i + 1, l, mid),
            queryMax(start, end, 2 * i + 2, mid + 1, r)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        set<int> obstacles;
        obstacles.insert(0);

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        segTree.resize(4 * (MAXX + 1), 0);

        vector<int> best(MAXX + 1, 0);

        auto it = obstacles.begin();
        auto prv = it;
        ++it;

        while (it != obstacles.end()) {

            int gap = *it - *prv;
            best[*it] = gap;

            prv = it;
            ++it;
        }

        for (int i = 0; i <= MAXX; i++) {
            if (best[i] != 0)
                update(i, best[i], 0, 0, MAXX);
        }

        vector<bool> ans;

        for (int qi = (int)queries.size() - 1; qi >= 0; qi--) {

            auto &q = queries[qi];

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                --it;

                int prevObstacle = *it;

                int largestFinishedGap =
                    queryMax(0, x, 0, 0, MAXX);

                int tailGap = x - prevObstacle;

                ans.push_back(
                    max(largestFinishedGap, tailGap) >= sz
                );
            }
            else {

                int x = q[1];

                auto cur = obstacles.find(x);

                auto left = prev(cur);
                auto right = next(cur);

                if (right != obstacles.end()) {

                    int mergedGap =
                        *right - *left;

                    update( *right, mergedGap, 0, 0, MAXX );
                }

                update(x, 0, 0, 0, MAXX );

                obstacles.erase(cur);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};