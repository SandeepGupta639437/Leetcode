class Solution {
public:
    int ans = 0;
    int  n;

    bool isSafe(int row,int col,vector<string>& board){
        // vertical
        for(int i= row-1;i>=0;i--){
            if (board[i][col] == 'Q')return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }
    
    void solve(int row,vector<string>& board){
        if(row==n){
            ans++;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(row,col,board)){
                board[row][col] = 'Q';
                solve(row+1,board);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int N) {
        n = N;
        vector<string>board(n,string(n,'.'));
        solve(0,board);
        return ans;
    }
};