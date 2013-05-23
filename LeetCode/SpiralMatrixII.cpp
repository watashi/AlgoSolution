class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(n, vector<int>(n, 1));
        
        int curr = 1;
        for (int i = 0; i <= n / 2; i ++) {  // Less than and equal to n / 2, remember to include it
            for (int j = i; j < n - i; j ++) {
                ans[i][j] = curr ++;
            }
            
            for (int j = i + 1; j < n - i; j ++) {
                ans [j][n - i - 1] = curr ++;
            }
            
            for (int j = n - i - 2; j >= i; j --) {
                ans[n - i - 1][j] = curr ++;
            }
            
            for (int j = n - i - 2; j > i; j --) {
                ans[j][i] = curr ++;
            }
        }
        
        return ans;
    }
};