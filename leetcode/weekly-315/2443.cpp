class Solution {
public:
  bool sumOfNumberAndReverse(int num) {
    for (int i = 0; i <= num; ++i) {
      int ii = 0;
      for (int j = i; j > 0; j /= 10) {
        ii = ii * 10 + j % 10;
      }
      if (i + ii == num) {
        return true;
      }
    }
    return false;
  }
};
