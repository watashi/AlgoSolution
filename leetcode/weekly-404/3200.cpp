
class Solution {
public:
  int maxHeightOfTriangle(int red, int blue) {
    int x = 0, y = 1;
    if (red > blue) {
      swap(red, blue);
    }
    for (int i = 2; ; ++i) {
      if (i % 2 == 0) {
        x += i;
      }
      else {
        y += i;
      }
      if (min(x, y) > red || max(x, y) > blue) {
        return i - 1;
      }
    }
    return -1;
  }
};
