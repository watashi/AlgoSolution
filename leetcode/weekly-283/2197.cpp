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
    struct Range {
        int start, end, lcm;
    };
    
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<Range> v;
        for (int i = 0; i < (int)nums.size(); ++i) {
            v.push_back({i, i, nums[i]});
        }
        DisjointSet ds;
        ds.init(v.size());
        queue<int> q;
        for (int i = 0; i < (int)v.size(); ++i) {
            q.push(i);
        }
        while (!q.empty()) {
            int x = ds.getp(q.front());
            auto& vx = v[x];
            q.pop();
            bool changed = false;
            if (vx.start - 1 >= 0) {
                int y = ds.getp(vx.start - 1);
                int g = gcd(vx.lcm, v[y].lcm);
                if (g > 1) {
                    ds.setp(y, x);
                    vx.start = v[y].start;
                    vx.lcm /= g;
                    vx.lcm *= v[y].lcm;
                    changed = true;
                }
            }
            if (vx.end + 1 < (int)v.size()) {
                int y = ds.getp(vx.end + 1);
                int g = gcd(vx.lcm, v[y].lcm);
                if (g > 1) {
                    ds.setp(y, x);
                    vx.end = v[y].end;
                    vx.lcm /= g;
                    vx.lcm *= v[y].lcm;
                    changed = true;
                }
            }
            if (changed) {
                if (vx.start - 1 >= 0) {
                    q.push(vx.start - 1);
                }
                if (vx.end + 1 < (int)v.size()) {
                    q.push(vx.end + 1);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < (int)v.size(); i = v[i].end + 1) {
            i = ds.getp(i);
            ans.push_back(v[i].lcm);
        }
        return ans;
    }
};
