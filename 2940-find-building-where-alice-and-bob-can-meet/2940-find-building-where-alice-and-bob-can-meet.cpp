class Solution {
public:
    int *constructST(vector<int>& heights,int  n){
        int *segTree = new int[4*n];
        buildSegTree(0,0,n-1,segTree,heights);
        return segTree;
    }
    void buildSegTree(int i,int l,int r,int segTree[],vector<int>&heights){
        if(l==r){
            segTree[i] = l;
            return ; 
        }
        int mid = l + (r - l)/2;
        buildSegTree(2*i+1,l,mid,segTree,heights);
        buildSegTree(2*i+2,mid+1,r,segTree,heights);

        int left_index = segTree[2*i+1];
        int right_index = segTree[2*i+2];

        segTree[i] = (heights[left_index]>heights[right_index]) ? left_index : right_index;

    }
    
    int querySegTreee(int start,int end,int i,int l,int r,int st[],vector<int>&heights){
        if(l>end ||  r<start){
            return -1;
        }
        if(l>=start && r<=end){
            return st[i];
        }

        int mid = l + (r-l)/2;

        int left_index = querySegTreee(start,end,2*i+1,l,mid,st,heights);
        int right_index = querySegTreee(start,end,2*i+2,mid+1,r,st,heights);

        if(left_index==-1)return right_index;
        if(right_index ==-1)return left_index;

       return (heights[left_index]>heights[right_index]) ? left_index : right_index;

    }


    int RMIQ(int st[],vector<int>&heights,int n,int start,int end){
          return querySegTreee(start,end,0,0,n-1,st,heights);
    }




    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();

        int *segTree = constructST(heights,n);
        vector<int>result;
        for(auto it:queries){
            int max_idx = max(it[0],it[1]);
            int min_idx = min(it[0],it[1]);

            if(min_idx == max_idx){
                result.push_back(max_idx); //or min idx
                continue;
            }else if(heights[max_idx]>heights[min_idx]){
                result.push_back(max_idx);
                continue;
            }


            int l = max_idx+1;
            int r = n-1;
            int result_idx = INT_MAX;
            while(l<=r){
                int mid = l + (r-l)/2;
                int idx = RMIQ(segTree,heights,n,l,mid); //return the index of max element in range l to mid
                if(heights[idx]>max(heights[min_idx],heights[max_idx])){
                    result_idx = min(result_idx,idx);
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            if(result_idx == INT_MAX){
                result.push_back(-1);
            }else{
                result.push_back(result_idx);
            }
        }
        return  result;
    }
};