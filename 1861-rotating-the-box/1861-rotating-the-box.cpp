class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& G) {
        int m = G.size();
        int n = G[0].size();

        for (int i = 0; i < m; i++) {
            int k = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (G[i][j] == '.')
                    continue;

                if (G[i][j] == '*') {
                    k = j - 1;
                }

                if (G[i][j] == '#') {
                    G[i][j] = '.';
                    G[i][k] = '#';
                    k--;
                }
            }
        }

        vector<vector<char>> G_(n, vector<char>(m));

        // int J = m-1;

        // for(int i=0;i<m;i++){
        //     int I = 0;
        //     for(int j =0;j<n;j++){
        //         G_[I][J] = G[i][j];
        //         I++;
        //     }
        //     J--;
        // }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                G_[j][m - 1 - i] = G[i][j];
            }
        }

        return G_;
    }
};