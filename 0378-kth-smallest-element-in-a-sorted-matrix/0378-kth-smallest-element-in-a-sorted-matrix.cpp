class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        // vector<int>new1;
        // for(int i=0;i<n;i++){
        //  for(int j=0;j<m;j++){
        //     new1.push_back(matrix[i][j]);
        //  }
        // }
        // // sort(new1.begin(),new1.end());
        // nth_element(new1.begin(), new1.begin() + k - 1, new1.end());
        // int ans=new1[k-1];
        // return ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0], {i, 0}});
        }
        while(k--){
            auto [val, pos] = pq.top();
            auto [row, col] = pos;
            pq.pop();
            if (col+1<m) {
                pq.push({matrix[row][col + 1], {row, col + 1}});
            }
            if(k==0)return val;
        }
        return pq.top().first;
    }
};