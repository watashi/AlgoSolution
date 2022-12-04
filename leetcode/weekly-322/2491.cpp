class Solution {
public:
  long long dividePlayers(vector<int>& skill) {
    auto v = skill;
    sort(v.begin(), v.end());
    int s = v.front() + v.back();
    long long ret = 0;
    for (int i = 0, j = (int)v.size() - 1; i < j; ++i, --j) {
      if (v[i] + v[j] != s) {
        return -1;
      }
      ret += (long long)v[i] * v[j];
    }
    return ret;
  }
};
