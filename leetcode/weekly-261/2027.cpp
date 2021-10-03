class Solution {
public:
  int minimumMoves(string s) {
    int x = 0, y = 0;
    for (char c : s) {
      if (c != 'O') {
        if (x <= 0) {
          x = 3;
          ++y;
        }
      }
      --x;
    }
    return y;
  }
};
