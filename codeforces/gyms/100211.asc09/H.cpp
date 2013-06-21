#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 64;

template<typename T>
struct index_cmp {
  const T* a;

  index_cmp(const T* a) : a(a) { }

  bool operator()(int lhs, int rhs) const {
    return a[lhs] < a[rhs];
  }
};

int main() {
  int n, t, c[MAXN], a, b, ans[10][5];
  vector<int> v[MAXN], w[6];

#ifndef __WATASHI__
  freopen("tickets.in", "r", stdin);
  freopen("tickets.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= 4; ++i) {
    w[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &t, &c[i]);
    v[i].resize(t);
    w[t].push_back(i);
    for (int j = 0; j < t; ++j) {
      scanf("%d", &v[i][j]);
    }
  }
  for (int i = 1; i <= 4; ++i) {
    sort(w[i].rbegin(), w[i].rend(), index_cmp<int>(c));
  }

  t = 0;
  a = b = 0;
  for (int i = 0, ti = 0; i <= (int)w[4].size(); ++i) {
    for (int j = 0, tj = ti; j <= (int)w[3].size() && i + j <= 9; ++j) {
      vector<int> w2(w[2]);
      int tk = tj;
      if (i < (int)w[4].size()) {
        w2.push_back(w[4][i]);
      }
      if (j < (int)w[3].size()) {
        w2.push_back(w[3][j]);
      }
      sort(w2.rbegin(), w2.rend(), index_cmp<int>(c));
      for (int k = 0; k < (int)w2.size() && k < 2 * (9 - i - j); ++k) {
        tk += 2 * c[w2[k]];
      }
      if (t < tk) {
        a = i;
        b = j;
        t = tk;
      }
      if (j < (int)w[3].size()) {
        tj += 6 * c[w[3][j]];
      }
    }
    if (i < (int)w[4].size()) {
      ti += 12 * c[w[4][i]];
    }
  }

  fill(ans[0], ans[9], 0);
  for (int i = 0; i < a; ++i) {
    copy(v[w[4][i]].begin(), v[w[4][i]].end(), ans[i]);
    v[w[4][i]].clear();
  }
  if (a < (int)w[4].size()) {
    w[2].push_back(w[4][a]);
  }
  for (int i = 0; i < b; ++i) {
    copy(v[w[3][i]].begin(), v[w[3][i]].end(), ans[a + i]);
    v[w[3][i]].clear();
  }
  if (b < (int)w[3].size()) {
    w[2].push_back(w[3][b]);
  }
  sort(w[2].rbegin(), w[2].rend(), index_cmp<int>(c));
  for (int i = 0; i < (int)w[2].size() && i < 2 * (9 - a - b); ++i) {
    copy(v[w[2][i]].begin(), v[w[2][i]].begin() + 2, ans[a + b + i / 2] + i % 2 * 2);
    v[w[2][i]].erase(v[w[2][i]].begin(), v[w[2][i]].begin() + 2);
  }
  for (int i = 1; i < n; ++i) {
    v[0].insert(v[0].end(), v[i].begin(), v[i].end());
  }
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (ans[i][j] == 0 && !v[0].empty()) {
        ans[i][j] = v[0].back();
        v[0].pop_back();
      }
    }
  }

  printf("%d\n", t);
  for (int i = 0; i < 9; ++i) {
    printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
  }

  return 0;
}

