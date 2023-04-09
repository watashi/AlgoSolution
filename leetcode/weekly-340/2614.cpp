class Solution {
public:
  static bool isPrime(int x) {
    if (x % 2 == 0) {
      return x == 2;
    }
    if (x < 3) {
      return false;
    }
    for (int i = 3; i * i <= x; i += 2) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  }

  int diagonalPrime(vector<vector<int>>& a) {
    int n = a.size();
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      int x = a[i][i];
      if (x > ret && isPrime(x)) {
        ret = x;
      }
      x = a[i][n - 1 - i];
      if (x > ret && isPrime(x)) {
        ret = x;
      }
    }
    return ret;
  }
};
