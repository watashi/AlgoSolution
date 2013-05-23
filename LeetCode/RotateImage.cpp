class Solution {
public:
    int N;
    void rotate(int r, int c, vector<vector<int> > &matrix) {
        int tmp = matrix[r][c];
        
        matrix[r][c] = matrix[N - 1 - c][r];
        matrix[N - 1 - c][r] = matrix[N - 1 - r][N - 1 - c];
        matrix[N - 1 - r][N - 1 - c] = matrix[c][N - 1 - r];
        matrix[c][N - 1 - r] = tmp;
    }
    
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        N = matrix.size();
        
        for (int i = 0; i < N / 2; i ++) {
            // Rotate the triangle ...
            for (int j = i; j < N - 1 - i; j ++) {
                rotate(i, j, matrix);
            }
        }
    }
};