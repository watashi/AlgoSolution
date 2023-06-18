class Solution {
public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int ret = mainTank + min(additionalTank, (mainTank - 1) / 4);
    ret *= 10;
    return ret;
  }
};
