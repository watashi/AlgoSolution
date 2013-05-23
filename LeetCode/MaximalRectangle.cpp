class Solution {
public:
  vector<vector<int> > sum;
  
  void calcSum(const vector<vector<char> > &matrix) {
    sum.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
    
    for (int i = 0; i < matrix.size(); i ++) {
      for (int j = 0; j < matrix[i].size(); j ++) {
        sum[i][j] = matrix[i][j] - '0';
        
        if (!i && j) sum[i][j] += sum[i][j - 1];
        else if (i && !j) sum[i][j] += sum[i - 1][j];
        else if (i && j) sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      }
    }
  }
  
  bool isRectangle(int row, int col, int width, int height, int & s) {
    s = sum[row + height - 1][col + width - 1];
    if (row > 0) s -= sum[row - 1][col + width - 1];
    if (col > 0) s -= sum[row + height - 1][col - 1];
    if (row > 0 && col > 0) s += sum[row - 1][col - 1];
    //cout << row << ' ' << col << ' ' << width << ' ' << height << ' ' << s << endl;

    return s == width * height;
  }
  
  int maximalRectangle(vector<vector<char> > &matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (matrix.size() == 0) return 0;

    calcSum(matrix);
    
    int ans = 0, s = 0;
    
    // N * N * N time complexity
    for (int l = 0; l < matrix[0].size(); l ++) {
        for (int w = matrix[0].size() - l; w > 0; w --) {
            if (matrix.size() * w <= ans) break;
            
            // We only need to calculate the maximal continuous subRectange whose height is 1
            int height = 0;
            for (int i = 0; i < matrix.size(); i ++) {
                if (isRectangle(i, l, w, 1, s)) {
                    height ++;
                    ans = max(ans, w * height);
                } else height = 0;
            }
        }
    }
    
    return ans;
  }
};
