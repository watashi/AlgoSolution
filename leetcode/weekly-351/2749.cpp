class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    long long y = num1, x = num2;
    for (int i = 1; i < 64; ++i) {
      long long z = y - i * x;
      if (z >= i && __builtin_popcountll(z) <= i) {
        return i;
      }
    }
    return -1;
  }
};
