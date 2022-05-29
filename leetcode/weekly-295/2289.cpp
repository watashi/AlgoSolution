class Solution {
public:
  int totalSteps(vector<int>& v) {
    int ret = 0;
    int n = v.size();
    vector<int> pl(n), pr(n);
    vector<bool> todo(n, true);
    for (int i = 0; i < n; ++i) {
      pl[i] = i - 1;
      pr[i] = i + 1;
    }
    vector<int> del;
    for (int i = 1; i < n; ++i) {
      if (v[i - 1] > v[i]) {
        del.push_back(i);
      }
    }
    while (!del.empty()) {
      set<int> pending;
      for (int i : del) {
        if (pl[i] >= 0 && pr[i] < n) {
          pending.insert(pl[i]);
        }
        if (pl[i] >= 0) {
          pr[pl[i]] = pr[i];
        }
        if (pr[i] < n) {
          pl[pr[i]] = pl[i];
        }
        todo[i] = false;
      }
      del.clear();
      for (int i : pending) {
        if (0 <= i && todo[i] && pr[i] < n && todo[pr[i]] && v[i] > v[pr[i]]) {
          del.push_back(pr[i]);
        }
      }
      ++ret;
      /*
      for (int i = 0; i < n; ++i) {
        if (todo[i]) {
          printf("%d, ", v[i]);
        }
      }
      puts("");
      */
    }
    return ret;
  }
};
