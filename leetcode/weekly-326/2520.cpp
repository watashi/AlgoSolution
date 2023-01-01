class Solution {
public:
  int countDigits(int num) {
    int ret = 0;
    for (int i = num; i > 0; i /= 10) {
      int d = i % 10;
      if (d > 0 && num % d == 0) {
        ++ret;
      }
    }
    return ret;
  }
};
