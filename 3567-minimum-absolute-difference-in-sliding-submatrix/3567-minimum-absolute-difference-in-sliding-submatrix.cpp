class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans_(m-k+1,vector<int>(n-k+1));
        for(int i=0;i<=m-k;i++){
         for(int j=0;j<=n-k;j++){
            set<int>st;
            for(int i_=i;i_<i+k;i_++){
                for(int j_=j;j_<j+k;j_++){
                    st.insert(grid[i_][j_]);
                }
            }
            int ans = INT_MAX;
            if(st.size() <= 1) ans = 0;
            else{
                int prev;
                bool first = true;

                for(auto it:st){
                    if(!first){
                        ans = min(ans, abs(prev - it));
                    }
                    prev = it;
                    first = false;
                }
                ans_[i][j]=ans;
            }
          }
        }
        return ans_;
    }
};