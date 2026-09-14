class SegmentTree{
public:

    struct Node {
        int pre = 0; 
        int suf = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> segTree; //segmen tree size 4*n

    SegmentTree(string& s){
        n = s.length();
        segTree.assign(4 * n, Node()); //segmen tree size 4*n

        buildSegmentTree(0, 0, n - 1, s);
    }

    Node merge(const Node& L, const Node& R, int leftLen, int rightLen) {
        Node res;

        res.leftChar  = L.leftChar; // left waale ka leftmost character hi parent ka leftmost character hoga
        res.rightChar = R.rightChar; // right ka rightmost character hi parent ka rightmost character hoga

        res.pre = L.pre;             //  result ka prefix count left waale ke prefix count ke brabr hoga
        if (L.pre == leftLen && L.rightChar == R.leftChar) {  // agr "aaaa" aur "aabcd" ko merge krenge to aaaaaabcd hoga ..jiska prefix 6 ho jayega
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;            //  result ka prefix count right waale ke prefix count ke brabr hoga
        if (R.suf == rightLen && L.rightChar == R.leftChar) {
            res.suf = R.suf + L.suf;
        }

        res.maxLen = max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    void buildSegmentTree(int i, int l, int r, string& s) {
        if (l == r) {
            segTree[i] = { 1, 1, 1, s[l], s[l] };
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) { //l == r == pos
            segTree[i] = { 1, 1, 1, ch, ch };
            return;
        } 
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    void update(int pos,char ch){
        return update(0,0,n-1,pos,ch);
    }

};

class Solution {
public:

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k = queryIndices.size();

        SegmentTree st(s);

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            st.update(pos,ch);
            
            result[i] = st.segTree[0].maxLen; //root node covers entire string
        }

        return result;
    }
};
