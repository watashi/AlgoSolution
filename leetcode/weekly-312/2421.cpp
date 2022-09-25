struct DisjointSet {
  vector<int> p;

  void init(int n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return i == p[i] ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    p[i] = j;
    return i != j;
  }
};

class Solution {
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    map<int, vector<pair<int, int>>> e;
    for (const auto& i : edges) {
      int a = i[0], b = i[1];
      e[max(vals[a], vals[b])].emplace_back(a, b);
    }

    int n = vals.size();
    int ret = n;
    DisjointSet ds;
    vector<pair<int, int>> c;
    c.reserve(n);
    for (int i : vals) {
      c.emplace_back(i, 1);
    }
    ds.init(n);
    for (const auto& es : e) {
      int k = es.first;
      multiset<int> ms;
      for (const auto& i : es.second) {
        int a = i.first, b = i.second;
        a = ds.getp(a);
        b = ds.getp(b);
        assert(a != b);
        if (c[a].first != c[b].first) {
          c[b] = max(c[a], c[b]);
        }
        else {
          int ca = c[a].second;
          int cb = c[b].second;
          if (ca > 1) {
            ms.erase(ca);
          }
          if (cb > 1) {
            ms.erase(cb);
          }
          c[b].second += c[a].second;
          ms.insert(c[b].second);
        }
        assert(c[b].first == k);
        ds.setp(a, b);
      }
      for (int i : ms) {
        ret += i * (i - 1) / 2;
      }
    }
    return ret;
  }
};
