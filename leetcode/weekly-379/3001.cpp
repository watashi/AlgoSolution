class Solution {
public:
  bool between(int from, int mid, int to) {
    return from <= to ? from <= mid && mid <= to : between(to, mid, from);
  }

  void transform(int& x, int& y) {
    int u = x + y;
    int v = x - y;
    x = u;
    y = v;
  }

  int minMovesToCaptureTheQueen(int rx, int ry, int bx, int by, int qx, int qy) {
    if (rx == qx && !(bx == qx && between(ry, by, qy))) {
      return 1;
    }
    if (ry == qy && !(by == qy && between(rx, bx, qx))) {
      return 1;
    }
    transform(rx, ry);
    transform(bx, by);
    transform(qx, qy);
    if (bx == qx && !(rx == qx && between(by, ry, qy))) {
      return 1;
    }
    if (by == qy && !(ry == qy && between(bx, rx, qx))) {
      return 1;
    }
    return 2;
  }
};
