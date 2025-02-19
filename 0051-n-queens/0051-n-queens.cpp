class Solution {
public:
    // Adds the current board configuration to the answer
    void addsolution(vector<string>& board, vector<vector<string>>& ans) {
        ans.push_back(board);
    }

    // Checks if it's safe to place a queen at board[row][col]
    bool issafe(int row, int col, vector<string>& board, int n) {
        int x = row;
        int y = col;

        // Check for queen in the same row (left side)
        while (y >= 0) {
            if (board[x][y] == 'Q') return false;
            y--;
        }

        // Check for queen in upper-left diagonal
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') return false;
            x--;
            y--;
        }

        // Check for queen in lower-left diagonal
        x = row;
        y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q') return false;
            x++;
            y--;
        }
        return true;
    }

    // Recursively tries to place queens in each column
    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n) {
        // All queens are placed successfully
        if (col == n) {
            addsolution(board, ans);
            return;
        }

        // Try placing a queen in all rows one by one
        for (int row = 0; row < n; row++) {
            if (issafe(row, col, board, n)) {
                board[row][col] = 'Q';    // Place queen
                solve(col + 1, ans, board, n); // Recursive call for next column
                board[row][col] = '.';   // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize board with '.'
        solve(0, ans, board, n);
        return ans;
    }
};
