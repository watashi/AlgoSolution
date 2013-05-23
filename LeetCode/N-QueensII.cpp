class Solution {
public:
    int ans;
    
    void solve(int n, int curr, vector<bool> & check, vector<int> & columns) {
        if (n == curr) {
            ans ++;
            return;
        }
        
        for (int i = 0; i < n; i ++) {
            if (check[i]) continue;
            if (check[n + i + curr]) continue;
            if (check[4 * n + i - curr]) continue;
            
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
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans = 0;
        
        vector<int> columns(n, -1);
        vector<bool> check(6 * n, false);
        
        solve(n, 0, check, columns);
        
        return ans;
    }
};

