class Solution {
public:
  bool stoneGameIX(vector<int> &stones) {
    vector<int> c(3, 0);
    for (int i : stones) {
      ++c[i % 3];
    }
    c[0] %= 2;
    if (c[0] == 0) {
      if (c[1] > 0 && c[2] > 0) {
        return true;
      } else {
        return false;
      }
    } else {
      if (c[1] > c[2] + 2 || c[2] > c[1] + 2) {
        return true;
      } else {
        return false;
      }
    }
  }
};
