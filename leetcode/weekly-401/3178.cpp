class Solution {
public:
  int numberOfChild(int n, int k) {
    k %= 2 * (n - 1);
    if (k < n) {
      return k;
    }
    else {
      return (n - 2) - (k - n);
    }
  }
};
