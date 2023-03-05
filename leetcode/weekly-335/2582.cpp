class Solution {
public:
  int passThePillow(int n, int time) {
    int m = (n - 1) * 2;
    time %= m;
    if (time <= n - 1) {
      return time + 1;
    }
    else {
      return n - (time - n + 1);
    }
  }
};
