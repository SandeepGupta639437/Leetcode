class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    int merge(int left, int right) {
        return left + right;
    }

    void update(int node, int l, int r, int idx, int delta) {
        if (l == r) {
            tree[node] += delta;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, delta);
        else
            update(node * 2 + 1, mid + 1, r, idx, delta);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return merge(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    void update(int idx, int delta) {
        update(1, 0, n - 1, idx, delta);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int n = nums.size();

        // Prefix sums
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        // Coordinate Compression
        vector<long long> values;

        for (long long x : prefix) {
            values.push_back(x);
            values.push_back(x - lower);
            values.push_back(x - upper);
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        SegmentTree st(values.size());

        int ans = 0;

        // Insert prefix sum = 0
        int pos = lower_bound(values.begin(), values.end(), 0LL) - values.begin();
        st.update(pos, 1);

        for (int i = 1; i <= n; i++) {

            long long cur = prefix[i];

            long long leftValue = cur - upper;
            long long rightValue = cur - lower;

            int left =
                lower_bound(values.begin(), values.end(), leftValue) - values.begin();

            int right =
                upper_bound(values.begin(), values.end(), rightValue) - values.begin() - 1;

            ans += st.query(left, right);

            int idx =
                lower_bound(values.begin(), values.end(), cur) - values.begin();

            st.update(idx, 1);
        }

        return ans;
    }
};