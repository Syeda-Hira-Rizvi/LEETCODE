class Solution {
public:
    bool validBox(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        //3*3
        unordered_set<char> st;
        for(int i = sr; i < er; i++) {
            for(int j = sc; j < ec; j++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end())
                    return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows = 9
        //cols = 9
        //validate rows
        for(int row = 0; row < 9; row++) {
            unordered_set<char> st;
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end())
                    return false;
                st.insert(board[row][col]);
            }
        }
        
   //validate columns
        for(int col = 0; col < 9; col++) {
            unordered_set<char> st;
            for(int row = 0; row < 9; row++) {
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end())
                    return false;
                st.insert(board[row][col]);
            }
        }
        //validate boxes
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(!validBox(board, i * 3, (i + 1) * 3, j * 3, (j + 1) * 3))
                    return false;
            }
        }
        return true;
    }
};