class Solution {
public:
  int alternateDigitSum(int n) {
    int s = 0, p = 1;
    while (n > 0) {
      s += p * n % 10;
      n /= 10;
      p *= -1;
    }
    return s * -p;
  }
};
