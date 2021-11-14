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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DisjointSet ds;
        vector<bool> ret;
        ds.init(n);
        for (const auto& req: requests) {
            int x = ds.getp(req[0]), y = ds.getp(req[1]);
            if (x == y) {
                ret.push_back(true);
                continue;
            }
            bool ok = true;
            for (const auto& res: restrictions) {
                int xx = ds.getp(res[0]), yy = ds.getp(res[1]);
                if ((x == xx && y == yy) || (x == yy && y == xx)) {
                    ok = false;
                    break;
                }
            }
            ret.push_back(ok);
            if (ok) {
                ds.setp(x, y);
            }
        }
        return ret;
    }
};
