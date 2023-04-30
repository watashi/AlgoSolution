class Solution {
public:
  static int score(const vector<int>& v) {
    int s = 0, c = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      if (i >= 3 && v[i - 3] == 10) {
        --c;
      }
      s += v[i];
      if (c > 0) {
        s += v[i];
      }
      if (v[i] == 10) {
        ++c;
      }
    }
    return s;
  }

  int isWinner(vector<int>& player1, vector<int>& player2) {
    auto s1 = score(player1), s2 = score(player2);
    if (s1 > s2) {
      return 1;
    }
    else if (s1 < s2) {
      return 2;
    }
    else {
      return 0;
    }
  }
};
