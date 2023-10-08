class Solution {
public:
  vector<int> countVisitedNodes(vector<int>& e) {
    int n = e.size();
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
      if (ret[i] != 0) {
        continue;
      }
      vector<int> v;
      v.push_back(i);
      ret[i] = -1;
      while (true) {
        int from = v.back();
        int to = e[from];
        int loop = ret[to];
        if (loop == 0) {
          v.push_back(to);
          ret[to] = -1;
          continue;
        }
        if (loop == -1) {
          auto it = find(v.begin(), v.end(), to);
          loop = v.end() - it;
          for_each(it, v.end(), [loop, &ret](int j) {ret[j] = loop; });
          v.erase(it, v.end());
        }
        while (!v.empty()) {
          ret[v.back()] = ++loop;
          v.pop_back();
        }
        break;
      }
    }
    return ret;
  }
};
