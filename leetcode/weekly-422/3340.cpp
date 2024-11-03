class Solution {
public:
  bool isBalanced(string num) {
    int s = 0, f = 1;
    for (char c : num) {
      s += (c - '0') * f;
      f *= -1;
    }
    return s == 0;
  }
};
