class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> ans;
        if (matrix.size() <= 0) return ans;
        
        int N = matrix.size(), M = matrix[0].size();
        int target = N * M;
        
        for (int i = 0; i <= N / 2 && ans.size() < target; i ++) {
            for (int j = i; j < M - i && ans.size() < target; j ++) {
                ans.push_back(matrix[i][j]);
            }
            
            for (int j = i + 1; j < N - i && ans.size() < target; j ++) {
                ans.push_back(matrix[j][M - i - 1]);
            }
            
            for (int j = M - i - 2; j >= i && ans.size() < target; j --) {
                ans.push_back(matrix[N - i - 1][j]);
            }
            
            for (int j = N - i - 2; j > i && ans.size() < target; j --) {
                ans.push_back(matrix[j][i]);
            }
        }
        
        return ans;
    }
};