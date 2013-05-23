class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = matrix.size();
        if (N <= 0) return;
        int M = matrix[0].size();
        
        bool row[N], col[M];
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                if (matrix[i][j] == 0) row[i] = col[j] = true;
            }
        }
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                if (row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};