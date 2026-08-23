class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    bool isSafe(int row, int col, int n) {

        // Same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // Upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    void solve(int row, int n) {

        // All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column
        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, n)) {

                // Choose
                board[row][col] = 'Q';

                // Explore
                solve(row + 1, n);

                // Undo / Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        board = vector<string>(n, string(n, '.'));

        solve(0, n);

        return ans;
    }
};