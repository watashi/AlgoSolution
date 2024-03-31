class Solution {
public:
  int maxBottlesDrunk(int a, int b) {
    int ret = 0;
    while (a >= b) {
      ret += b;
      a -= b - 1;
      ++b;
    }
    ret += a;
    return ret;
  }
};
