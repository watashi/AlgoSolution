class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = obstacleGrid.size();
        if (N <= 0) return 0;
        int M = obstacleGrid[0].size();
        vector<vector<int> > dp(N, vector<int>(M, 0));
        
        for (int i = 0; i < M; i ++) {
            if (obstacleGrid[0][i] == 1) break;
            dp[0][i] = 1;
        }
        
        for (int i = 0; i < N; i ++) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }
        
        for (int i = 1; i < N; i ++) {
            for (int j = 1; j < M; j ++) {
                if (!obstacleGrid[i][j]) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[N - 1][M - 1];
    }
};