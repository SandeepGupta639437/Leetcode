class Solution {
public:
    vector<vector<string>> ans;
    int n;

    bool issafe(int row, int col, vector<string>& board) {

        // Check same column
        for (int i = row - 1; i >= 0; i--)
            if (board[i][col] == 'Q')
                return false;

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    // Recursively tries to place queens in each column
    void solve(int row, vector<string>& board) {
        // All queens are placed successfully
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in all rows one by one
        for (int col = 0; col < n; col++) {
            if (issafe(row, col, board)) {
                board[row][col] = 'Q';    // Place queen
                solve(row + 1, board); // Recursive call for next row
                board[row][col] = '.';   // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        vector<string> board(n, string(n, '.')); // Initialize board with '.'
        solve(0, board);
        return ans;
    }
};
