class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solveboard(board, n);
    }

    bool notclash(char num, int i, int j, vector<vector<char>>& board, int n) {
        for(int k = 0; k < n; k++) {
            // horizontal row
            if(board[i][k] == num) return false;
            // vertical column
            if(board[k][j] == num) return false;
        }
        
        // box
        int s = sqrt(n);
        // starting value of subbox
        int startrow = i - i % s;
        int startcol = j - j % s;
        for(int r = startrow; r < startrow + s; r++) {
            for(int c = startcol; c < startcol + s; c++) {
                if(board[r][c] == num) return false;
            }
        }
        return true;
    }

    bool solveboard(vector<vector<char>>& board, int n) {
        bool flag = false;
        int i, j;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(board[i][j] == '.') {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        if(!flag) return true;

        for(int num = 1; num <= n; num++) {
            // Check if it is not clashing
            if(notclash(num + 48, i, j, board, n)) {
                board[i][j] = num + 48;
                if(solveboard(board, n))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
};