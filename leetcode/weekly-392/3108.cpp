class Solution {
public:
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

  vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    DisjointSet ds;
    vector<int> w(n, -1);
    ds.init(n);
    for (const auto& e : edges) {
      int a = e[0], b = e[1], c = e[2];
      a = ds.getp(a);
      b = ds.getp(b);
      ds.setp(a, b);
      w[ds.getp(a)] = w[a] & w[b] & c;
    }
    vector<int> ret;
    for (const auto& q : query) {
      int a = q[0], b = q[1];
      if (a == b) {
	// SHITTY PROBLEM DESCRIPTION, this is not well-defined
        ret.push_back(0);
        continue;
      }
      a = ds.getp(a);
      b = ds.getp(b);
      if (a != b) {
        ret.push_back(-1);
      }
      else {
        ret.push_back(w[a]);
      }
    }
    return ret;
  }
};
