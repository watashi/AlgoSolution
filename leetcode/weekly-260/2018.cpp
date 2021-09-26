class Solution {
public:
    bool check(const string& s, const string& t) const {
        if (s.size() != t.size()) {
            return false;
        } else {
            for (size_t i = 0; i < s.size(); ++i) {
                if (s[i] != ' ' && s[i] != t[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || board[i - 1][j] == '#') {
                    string s;
                    for (int k = i; k < n && board[k][j] != '#'; ++k) {
                        s += board[k][j];
                    }
                    if (check(s, word)) {
                        return true;
                    }
                    reverse(s.begin(), s.end());
                    if (check(s, word)) {
                        return true;
                    }
                }
                if (j == 0 || board[i][j - 1] == '#') {
                    string s;
                    for (int k = j; k < m && board[i][k] != '#'; ++k) {
                        s += board[i][k];
                    }
                    if (check(s, word)) {
                        return true;
                    }
                    reverse(s.begin(), s.end());
                    if (check(s, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
