class Solution {
public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    for (int i = 0; i < (int)mat.size(); ++i) {
      vector<int> v = mat[i];
      int d = k % v.size();
      if (i % 2 == 0) {
        rotate(v.begin(), v.begin() + d, v.end());
      }
      else {
        rotate(v.begin(), v.end() - d, v.end());
      }
      if (v != mat[i]) {
        return false;
      }
    }
    return true;
  }
};

