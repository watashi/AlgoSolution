/**
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, 
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 */
class Solution {
public:
    vector<vector<string> > ans;
    
    void solve(int n, int curr, vector<bool> & check, vector<int> & columns) {
        // curr == n, find a solution
        if (n == curr) {
            vector<string> ret(n, string(n, '.'));
            
            for (int i = 0; i < n; i ++) {
                ret[i][columns[i]] = 'Q';
            }
            
            ans.push_back(ret);
            return;
        }
        
        // try every possible positions for next queen
        for (int i = 0; i < n; i ++) {
            // check if this column is used
            if (check[i]) continue;

            // check if the diagnal is used
            if (check[n + i + curr]) continue;
            if (check[4 * n + i - curr]) continue;
            
            // set mask
            check[i] = true;
            check[n + i + curr] = true;
            check[4 * n + i - curr] = true;
            columns[curr] = i;
            
            solve(n, curr + 1, check, columns);
            
            // backtracking
            check[i] = false;
            check[n + i + curr] = false;
            check[4 * n + i - curr] = false;
        }
    }
    
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        
        vector<int> columns(n, -1);
        vector<bool> check(6 * n, false);
        
        solve(n, 0, check, columns);
        
        return ans;
    }
};




/* 
// Another implementation

class Solution {
public:
    vector<vector<string> > ans;
    
    bool check(int n, int r, int c, long long flag, uint64_t & ret)
    {
        int result = true;
        if (flag & (1LL << c)) result = false;
        if (flag & (1LL << (n + r + c))) result = false;
        if (flag & (1LL << (4 * n + r - c))) result = false;
        
        if (result) {
            ret = flag;
            ret |= (1LL << c);
            ret |= (1LL << (n + r + c));
            ret |= (1LL << (4 * n + r - c));
        }
        
        return result;
    }
    
    void bitSolve(int n, int curr, long long flag, vector<int> & columns) {
        if (n == curr) {
            vector<string> ret(n, string(n, '.'));
            
            for (int i = 0; i < n; i ++) {
                ret[i][columns[i]] = 'Q';
            }
            
            ans.push_back(ret);
            return;
        }
        
        long long newFlag;
        for (int i = 0; i < n; i ++) {
            if (!check(n, curr, i, flag, newFlag)) continue;
    
            columns[curr] = i;
            bitSolve(n, curr + 1, newFlag, columns);
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        
        vector<int> columns(n, -1);
        
        bitSolve(n, 0, 0, columns);
        
        return ans;
    }
};

 */
