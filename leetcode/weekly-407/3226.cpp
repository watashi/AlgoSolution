class Solution {
public:
  int minChanges(int n, int k) {
    int m = n ^ k;
    if ((m & n) == m) {
      return __builtin_popcount(m);
    }
    else {
      return -1;
    }
  }
};
