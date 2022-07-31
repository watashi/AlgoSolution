class Solution {
public:
  int longestCycle(vector<int>& e) {
    int n = e.size();
    vector<int> d(n, -1);
    int ret = -1;
    for (int i = 0; i < n; ++i) {
      if (d[i] != -1) {
        continue;
      }
      vector<int> v;
      v.push_back(i);
      d[i] = 0;
      while (true) {
        int j = e[i];
        if (j == -1 || d[j] == -2) {
          break;
        }
        else if (d[j] >= 0) {
          ret = max(ret, d[i] - d[j] + 1);
          break;
        }
        else {
          v.push_back(j);
          d[j] = d[i] + 1;
          i = j;
        }
      }
      for (int j : v) {
        d[j] = -2;
      }
    }
    return ret;
  }
};
