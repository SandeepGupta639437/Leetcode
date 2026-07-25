class SegmentTree{
   public:
        vector<int>tree;
        int n;

        SegmentTree(vector<int>& v){
            n = v.size();
            tree.resize(4*n);
            build(1,0,n-1,v);
        }

        int merge(int left,int right){
            return left^right;
        }

        void build(int node,int l,int r,vector<int>& v){
            if(l==r){
                tree[node] = v[l];
                return ;
            }

            int mid = (l+r)/2;
            build(2*node,l,mid,v);
            build(2*node+1,mid+1,r,v);
            tree[node] = merge(tree[2*node] , tree[2*node+1]);
        }

        int query(int node,int l,int r,int ql,int qr){
            if(ql>r || qr<l)return 0;
            if(ql<=l && qr>=r)return tree[node];

            int mid = (l+r)/2;
            return merge(query(2*node,l,mid,ql,qr),query(2*node+1,mid+1,r,ql,qr));
        }

        void update(int node,int l,int r,int idx,int val){
            if(l==r){
                tree[node] = val;
            }
            int mid = (l+r)/2;

            if(idx<=mid){
                update(2*node,l,mid,idx,val);
            }else{
                update(2*node+1,mid+1,r,idx,val);
            }
            tree[node] = merge(tree[2*node],tree[2*node+1]);
        }

        int query(int left,int right){
            return query(1,0,n-1,left,right);
        }
};

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        SegmentTree st(arr);
        vector<int>ans;

        for(auto it:queries){
            int left = it[0];
            int right = it[1];
            ans.push_back(st.query(left,right));
        }
        return ans;
    }
};