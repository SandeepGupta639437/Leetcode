class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> next = matrix[n-1];
        vector<int> curr(n);

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {

                if(j == 0) {
                    curr[j] = matrix[i][j] + min(next[j], next[j+1]);
                }
                else if(j == n-1) {
                    curr[j] = matrix[i][j] + min(next[j], next[j-1]);
                }
                else {
                    curr[j] = matrix[i][j] +
                              min(next[j],
                              min(next[j-1], next[j+1]));
                }
            }

            next.swap(curr);
        }

        return *min_element(next.begin(), next.end());
    }
};