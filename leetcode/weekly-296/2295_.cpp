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
  vector<int> arrayChange(vector<int>& v, vector<vector<int>>& op) {
    DisjointSet ds;
    unordered_map<int, int> mp0, mp;
    unordered_set<int> dead;
    vector<int> rmp;
    ds.init(op.size() * 2);
    rmp.reserve(op.size() * 2);
    for (const auto& i : op) {
      int x = i[0], y = i[1];
      if (dead.count(x) > 0) {
        continue;
      }
      if (mp.count(x) == 0) {
        mp0.emplace(x, (int)rmp.size());
        mp[x] = (int)rmp.size();
        rmp.push_back(x);
      }
      if (mp.count(y) == 0) {
        mp[y] = (int)rmp.size();
        rmp.push_back(y);
      }
      ds.setp(mp[x], mp[y]);
      mp.erase(x);
      dead.erase(y);
    }
    vector<int> ret = v;
    for (auto& i : ret) {
      auto it = mp0.find(i);
      if (it != mp0.end()) {
        i = rmp[ds.getp(it->second)];
      }
    }
    return ret;
  }
};

/*
// Leetcode TL SUCKS
// It's aggregated, not per test case, this would result in TLE
class Solution {
public:
  vector<int> arrayChange(vector<int>& v, vector<vector<int>>& op) {
    static constexpr int MAXN = 1000100;
    vector<int> id, rid;
    id.reserve(MAXN);
    rid.reserve(MAXN + MAXN);
    for (int i = 0; i < MAXN; ++i) {
      id.push_back(i);
      rid.push_back(i);
    }

    DisjointSet ds;
    ds.init(MAXN + MAXN);
    for (const auto& i: op) {
      int a = i[0];
      int b = i[1];
      ds.setp(id[a], id[b]);
      id[a] = (int)rid.size();
      rid.push_back(a);
    }

    vector<int> ret;
    for (auto i : v) {
      ret.push_back(rid[ds.getp(i)]);
    }
    return ret;
  }
};
*/
