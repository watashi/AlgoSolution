class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.size() <= 0) return 0;
        
        int N = grid.size(), M = grid[0].size();
        vector<vector<int> > dp(N, vector<int>(M, 0));
        
        for (int i = 0; i < N; i ++) {
            if (i > 0) grid[i][0] += grid[i - 1][0];
            
            for (int j = 0; j < M; j ++) {
                if (i == 0 && j > 0) 
                    grid[i][j] += grid[i][j - 1];
                
                if (i == 0 || j == 0) continue;
                
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
            
        }
        
        return grid[N - 1][M - 1];
    }
};