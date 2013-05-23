class Solution {
public:
    
    set<int> x[9], y[9];
    int mp[9][9];
    
    void init() {
        memset(mp, 0, sizeof(mp));
        
        for (int i = 0; i < 9; i ++) {
            x[i].clear();
            y[i].clear();
        }
    }
    
    bool buildMap(vector<vector<char> >&board) {
        init();
        
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    mp[i][j] = n;
                    if (x[i].find(n) != x[i].end() || y[j].find(n) != y[j].end()) return false;
                    x[i].insert(n);
                    y[j].insert(n);
                }
            }
        }
        return true;
    }
    
    bool checkBlocks()
    {
        set<int> block;
        
        for (int r = 0; r < 3; r ++) {
            for (int c = 0; c < 3; c ++) {
                for (int i = 0; i < 3; i ++) {
                    for (int j = 0; j < 3; j ++) {
                        int n = mp[r * 3 + i][c * 3 + j];
                        if (n && block.find(n) != block.end()) {
                            return false;
                        }
                        
                        block.insert(n);
                    }
                }
                
                block.clear();
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!buildMap(board)) return false;
        
        return checkBlocks();
    }
};


class Solution2 {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<bool> > rows(9, vector<bool>(9, false));
        vector<vector<bool> > cols(9, vector<bool>(9, false));
        vector<vector<bool> > blocks(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int c = board[i][j] - '1';
                if (rows[i][c] || cols[j][c] || blocks[i - i % 3 + j / 3][c])
                    return false;
                rows[i][c] = cols[j][c] = blocks[i - i % 3 + j / 3][c] = true;
            }
        }
        return true;
    }
};