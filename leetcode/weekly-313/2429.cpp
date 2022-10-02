class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int n = 0;
    while (num2 > 0) {
      n += num2 & 1;
      num2 >>= 1;
    }
    int x = 0;
    for (int i = 31; i >= 0 && n > 0; --i) {
      if (((num1 >> i) & 1) != 0) {
        x ^= 1 << i;
        --n;
      }
    }
    for (int i = 0; i < 32 && n > 0; ++i) {
      if (((num1 >> i) & 1) == 0) {
        x ^= 1 << i;
        --n;
      }
    }
    return x;
  }
};
