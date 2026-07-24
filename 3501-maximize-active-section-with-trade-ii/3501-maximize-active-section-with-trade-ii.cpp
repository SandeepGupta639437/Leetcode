class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    // Merge Function (Range Maximum)
    int merge(int left, int right) {
        return max(left, right);
    }

    void build(int node, int l, int r, vector<int>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, arr);
        build(node * 2 + 1, mid + 1, r, arr);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
    int query(int node, int l, int r, int ql, int qr) {
        // No Overlap
        if (r < ql || l > qr) return INT_MIN;
        // Complete Overlap
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return merge( query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int n = s.size();
        int activeCount = count(s.begin(), s.end(), '1');

        vector<int> blockStart;
        vector<int> blockEnd;

        // Find all zero blocks
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0')
                    i++;
                blockStart.push_back(start);
                blockEnd.push_back(i - 1);
            } else {
                i++;
            }
        }

        int m = blockStart.size();

        // Less than two zero blocks
        if (m < 2) {
            return vector<int>(queries.size(), activeCount);
        }

        // Length of every zero block
        vector<int> blockSize(m);
        for (int i = 0; i < m; i++){
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }

        // pairSum[i] = blockSize[i] + blockSize[i+1]
        vector<int> pairSum;
        for (int i = 0; i + 1 < m; i++){
            pairSum.push_back(blockSize[i] + blockSize[i + 1]);
        }

        SegmentTree sy(pairSum);
        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int low = lower_bound(blockEnd.begin(), blockEnd.end(), l) - blockEnd.begin();
            int high = upper_bound(blockStart.begin(), blockStart.end(), r) - blockStart.begin() - 1;
            int maxPairSum = 0;

            if (low < high) {

                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1;
                int lastLen = min(blockEnd[high], r) - blockStart[high] + 1;

                if (high - low == 1) {
                    maxPairSum = firstLen + lastLen;

                } else {
                    int pair1 = firstLen + blockSize[low + 1];
                    int pair2 = blockSize[high - 1] + lastLen;
                    int middle = sy.query(low + 1, high - 2);

                    maxPairSum = max({pair1, pair2, middle});
                }
            }
            ans.push_back(activeCount + maxPairSum);
        }
        return ans;
    }
};