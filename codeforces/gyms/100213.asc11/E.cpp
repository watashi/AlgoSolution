#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int dx[] = {-1, -1, 0, 0, 1, 1};
const int dy[] = {-1, 0, -1, 1, -1, 0};
const int dz[] = {0, 1, -1, 1, 0, 1};

struct Islands {
  const int s;
  map<PII, int> mp;
  vector<int> p, c;

  Islands(int s) : s(s) {
  }

  int tryfind(const PII& xy) {
    return mp.count(xy) == 0 ? -1 : mp[xy];
  }

  int find(const PII& xy) {
    if (mp.count(xy) == 0) {
      int z = mp.size();
      p.push_back(z);
      c.push_back(1);
      return mp[xy] = z;
    } else {
      return mp[xy];
    }
  }

  int root(int i) {
    return i == p[i] ? i : p[i] = root(p[i]);
  }

  void add(const PII& xy) {
    if (tryfind(xy) != -1) {
      return;
    }

    int t = 1;
    vector<int> v;
    for (int i = 0; i < 6; ++i) {
      int z = tryfind(make_pair(xy.first + dx[i], xy.second + (xy.first % 2 == 0 ? dy[i] : dz[i])));
      if (z != -1) {
        z = root(z);
        if (std::find(v.begin(), v.end(), z) == v.end()) {
          v.push_back(z);
          t += c[z];
        }
      }
    }
    // printf("=> %d\n", t);

    if (t > s) {
      return;
    }

    int n = find(xy);
    for (int i = 0; i < 6; ++i) {
      int z = tryfind(make_pair(xy.first + dx[i], xy.second + (xy.first % 2 == 0 ? dy[i] : dz[i])));
      if (z != -1) {
        z = root(z);
        if (z != n) {
          p[z] = n;
          c[n] += c[z];
        }
      }
    }
  }
};

int main() {
  int n, s, x, y;

#ifndef __WATASHI__
  freopen("islands.in", "r", stdin);
  freopen("islands.out", "w", stdout);
#endif
  scanf("%d%d", &n, &s);
  Islands islands(s);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    islands.add(make_pair(x, y));
  }

  vector<int> ans;
  for (int i = 0; i < (int)islands.p.size(); ++i) {
    if (islands.p[i] == i) {
      ans.push_back(islands.c[i]);
    }
  }

  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}

