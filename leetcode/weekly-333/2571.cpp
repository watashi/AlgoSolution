class Solution {
public:
  int minOperations(int n) {
    int ret = 0;
    while (n > 0) {
      while (n % 2 == 0) {
        n /= 2;
      }
      int c = 0;
      while (n % 2 != 0) {
        n /= 2;
        ++c;
      }
      if (c == 1) {
        ++ret;
      }
      else {
        ++ret;
        ++n;
      }
    }
    return ret;
  }
};
