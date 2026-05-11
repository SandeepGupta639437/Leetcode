class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>new1;
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            new1.push_back(matrix[i][j]);
         }
        }
        sort(new1.begin(),new1.end());
        int ans=new1[k-1];
        return ans;
    }
};