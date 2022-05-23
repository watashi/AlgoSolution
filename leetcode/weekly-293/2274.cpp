class Solution {
public:
  int maxConsecutive(int bottom, int top, vector<int>& special) {
    vector<int> v = special;
    v.push_back(bottom - 1);
    v.push_back(top + 1);
    sort(v.begin(), v.end());
    int ret = 0;
    for (int i = 1; i < (int)v.size(); ++i) {
      ret = max(ret, v[i] - v[i - 1] - 1);
    }
    return ret;
  }
};
