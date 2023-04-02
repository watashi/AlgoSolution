class Solution {
public:
  vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
    const int r = k % 2 == 0 ? 1 : 2;
    set<int> todo[2];
    for (int i = 0; i < n; ++i) {
      todo[i % 2].insert(i);
    }
    for (int i : banned) {
      todo[i % 2].erase(i);
    }

    vector<int> dist(n, -1);
    vector<int> v;
    dist[p] = 0;
    todo[p % 2].erase(p);
    v.push_back(p);
    for (int d = 1; !v.empty(); ++d) {
      vector<int> w;
      for (int i : v) {
        int lo = max(i - (k - 1), (k - 1) - i);
        int hi = min(i + (k - 1), (n - 1) + (n - k) - i);
        // cout << i << " ==> " << lo << " , " << hi << endl;
        auto& st = todo[lo % 2];
        while (true) {
          auto it = st.lower_bound(lo);
          if (it == st.end() || *it > hi) {
            break;
          }
          int j = *it;
          dist[j] = d;
          st.erase(j);
          // cout << i << " => " << j << endl;
          w.push_back(j);
        }
      }
      v = move(w);
    }
    return dist;
  }
};
