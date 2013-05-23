class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() <= 0) return false;
        
        int r = 0, c = matrix[0].size() - 1;
        
        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] < target) r ++;
            else c --;
        }
        
        return false;
    }
};