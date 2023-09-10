
class Solution {
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int d = max(abs(fx - sx), abs(fy - sy));
    if (d == 0 && t == 1) {
      return false;
    }
    return d <= t;
  }
};
