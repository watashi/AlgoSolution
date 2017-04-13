class Solution {
public:
    bool isValid(vector<vector<char> > &board, int r, int c) {
        char tmp = board[r][c];
        board[r][c] = '.';
        
        for (int i = 0; i < 9; i ++) {
            if (board[r][i] == tmp || board[i][c] == tmp) return false;
        }

        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                int n = (r/3) * 3 + i;
                int m = (c/3) * 3 + j;
                
                if (board[n][m] == tmp) return false;
            }
        }
        
        board[r][c] = tmp;
        return true;
    }
    
    bool solve(vector<vector<char> > &board) {
        bool ret = true;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    ret = false;
                    for (char k = '1'; k <= '9'; k ++) {
                        board[i][j] = k;
                        if (isValid(board, i, j) && solve(board)) return true;
                    }
                    
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        
        return ret;
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        solve(board);    
    }
};