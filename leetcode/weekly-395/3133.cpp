class Solution {
public:
  long long minEnd(int n, int x) {
    long long y = x;
    --n;
    for (int i = 0; n > 0; ++i) {
      if ((y >> i) & 1) {
        continue;
      }
      else if (n & 1) {
        y ^= 1LL << i;
      }
      n >>= 1;
    }
    return y;
  }
};
