class Solution {
public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    set<pair<int, int>> es;
    vector<int> d(n, 0);
    for (const auto& i : edges) {
      int a = i[0] - 1, b = i[1] - 1;
      es.emplace(a, b);
      es.emplace(b, a);
      ++d[a];
      ++d[b];
    }
    vector<int> odds;
    for (int i = 0; i < n; ++i) {
      if (d[i] % 2 != 0) {
        odds.push_back(i);
      }
    }
    if (odds.empty()) {
      return true;
    }
    else if (odds.size() == 2) {
      int a = odds[0], b = odds[1];
      if (es.count(make_pair(a, b)) == 0) {
        return true;
      }
      for (int i = 0; i < n; ++i) {
        if (i != a && i != b && es.count(make_pair(a, i)) == 0 && es.count(make_pair(b, i)) == 0) {
          return true;
        }
      }
      return false;
    }
    else if (odds.size() == 4) {
      for (int i = 0; i < 3; ++i) {
        rotate(odds.data(), odds.data() + 1, odds.data() + 3);
        int a1 = odds[0];
        int b1 = odds[1];
        int a2 = odds[2];
        int b2 = odds[3];
        if (es.count(make_pair(a1, b1)) == 0 && es.count(make_pair(a2, b2)) == 0) {
          return true;
        }
      }
      return false;
    }
    else {
      return false;
    }
  }
};
