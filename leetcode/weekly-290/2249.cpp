
class Solution {
public:
  static int sq(int i) {
    return i * i;
  }

  int countLatticePoints(vector<vector<int>>& circles) {
    int ret = 0;
    for (auto& i : circles) {
      i[2] = sq(i[2]);
    }
    for (int x = 0; x <= 200; ++x) {
      for (int y = 0; y <= 200; ++y) {
        for (const auto& i : circles) {
          if (sq(i[0] - x) + sq(i[1] - y) <= i[2]) {
            ++ret;
            break;
          }
        }
      }
    }
    return ret;
  }
};
