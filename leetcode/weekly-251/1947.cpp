class Solution {
public:
  vector<int> encode(const vector<vector<int>>& v) {
    vector<int> ret;
    for (const auto& i: v) {
      int x = 0;
      for (const auto& j: i) {
        x <<= 1;
        x ^= j;
      }
      ret.push_back(x);
    }
    return ret;
  }

  void gao(vector<int>::const_iterator x, const vector<int>& y, int sum, int& ans) {
    if (y.empty()) {
      ans = min(ans, sum);
    } else {
      for (int i = 0; i < (int)y.size(); ++i) {
        auto t = y;
        t.erase(t.begin() + i);
        gao(x + 1, t, sum + __builtin_popcount(*x ^ y[i]), ans);
      }
    }
  }

  int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    int m = students.size();
    int n = students[0].size();
    int ans = m * n;
    auto x = encode(students), y = encode(mentors);
    gao(x.begin(), y, 0, ans);
    return m * n - ans;
  }
};
