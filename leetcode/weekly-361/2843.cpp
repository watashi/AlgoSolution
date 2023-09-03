class Solution {
public:
  static bool check(int x) {
    int d = 0, s = 0;
    for (int i = x; i > 0; i /= 10, ++d) {
      s += i % 10;
    }
    if (d % 2 != 0) {
      return false;
    }
    d /= 2;
    int t = 0;
    for (int i = x; i > 0 && d > 0; i /= 10, --d) {
      t += i % 10;
    }
    return s == t + t;
  }

  int countSymmetricIntegers(int low, int high) {
    int ret = 0;
    for (int i = low; i <= high; ++i) {
      if (check(i)) {
        ++ret;
      }
    }
    return ret;
  }
};
