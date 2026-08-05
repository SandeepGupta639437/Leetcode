class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = numRows;
        int m = s.size();

        vector<vector<char>> mat(n, vector<char>(m, '#'));

        int i = 0, j = 0;
        int k = 0;

        while (k < m) {

            // Go vertically down
            while (i < n && k < m) {
                mat[i][j] = s[k++];
                i++;
            }

            i -= 2;
            j++;

            // Go diagonally up
            while (i > 0 && k < m) {
                mat[i][j] = s[k++];
                i--;
                j++;
            }
        }

        string ans;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (mat[r][c] != '#')
                    ans += mat[r][c];
            }
        }

        return ans;
    }
};