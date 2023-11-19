class Solution {
public:
  int findMinimumOperations(string s1, string s2, string s3) {
    vector<string> v = { s1, s2, s3 };
    sort(v.begin(), v.end());
    int c = 0;
    while (c < v[0].size() && c < v[2].size() && v[0][c] == v[2][c]) {
      ++c;
    }
    if (c == 0) {
      return -1;
    }
    else {
      c *= -3;
      for (const auto& s : v) {
        c += s.size();
      }
      return c;
    }
  }
};
