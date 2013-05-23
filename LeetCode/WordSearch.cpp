class Solution {
public:

    bool searchDFS(int r, int c, int curr, const string &target, vector<vector<char> > &board, vector<vector<bool> > visited) {
                
        if (curr >= target.length()) return true;
    
        // The direction we search is very important, take care the sequence we assign x[] and y[]...
        int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
        int tr, tc;
        
        for (int i = 0; i < 4; i ++) {
            tr = r + x[i], tc = c + y[i];
            
            if (tr < 0 || tr >= board.size() || tc < 0 || tc >= board[r].size()) continue;
            if (visited[tr][tc] || target[curr] != board[tr][tc]) continue;
            
            visited[r][c] = true;
            if (searchDFS(tr, tc, curr + 1, target, board, visited)) return true;
            visited[r][c] = false;
        }
        
        return false; // Remember to return false at last...
    }
    

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (board.size() <= 0) return word.length() == 0;
        if (board.size() * board[0].size() < word.length()) return false;
        
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (searchDFS(i, j, 1, word, board, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }
        
        return false;
    }
};