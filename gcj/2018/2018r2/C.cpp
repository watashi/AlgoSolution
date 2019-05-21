#include <bits/stdc++.h>

using namespace std;

struct Hungarian {
  int nx, ny;
  vector<int> mx, my;
  vector<vector<int> > e;

  void init(int nx, int ny) {
    this->nx = nx;
    this->ny = ny;
    mx.resize(nx);
    my.resize(ny);
    e.clear();
    e.resize(nx);
    mark.resize(nx);
  }

  void add(int a, int b) {
    e[a].push_back(b);
  }

  // vector<bool> is evil!!!
  basic_string<bool> mark;

  bool augment(int i) {
    if (!mark[i]) {
      mark[i] = true;
      for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
        if (my[*j] == -1 || augment(my[*j])) {
          mx[i] = *j;
          my[*j] = i;
          return true;
        }
      }
    }
    return false;
  }

  int gao() {
    int ret = 0;
    fill(mx.begin(), mx.end(), -1);
    fill(my.begin(), my.end(), -1);
    for (int i = 0; i < nx; ++i) {
      fill(mark.begin(), mark.end(), false);
      if (augment(i)) {
        ++ret;
      }
    }
    return ret;
  }
} h;

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n;
    map<int, vector<pair<int, int>>> m;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int k;
        scanf("%d", &k);
        m[k].emplace_back(i, j);
      }
    }

    int ans = 0;
    for (const auto& i: m) {
      h.init(n, n);
      for (const auto& j: i.second) {
        h.add(j.first, j.second);
      }
      ans += (int)i.second.size() - h.gao();
    }
    printf("Case #%d: %d\n", ri, ans);
  }

  return 0;
}
