#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int p, m[12], l[12];
map<string, string> s;

void dfs(int n, const string& v) {
  if (n > 0) {
    for (int i = 0; i < p; ++i) {
      string w = v;
      rotate(w.begin(), w.begin() + m[i], w.begin() + l[i]);
      try {
        dfs(n - 1, w);
      } catch (string ex) {
        ex += (char)('1' + i);
        throw ex;
      }
    }
  } else if (s.count(v) != 0) {
    throw s[v];
  }
}

int main() {
  int n, q, x;
  string vs, vt;

#ifndef __WATASHI__
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);
#endif
  scanf("%d%d%d", &n, &q, &p);
  vs.resize(n);
  vt.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    vs[i] = (char)(x - 1);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    vt[i] = (char)(x - 1);
  }
  for (int i = 0; i < p; ++i) {
    scanf("%d%d", &l[i], &m[i]);
    l[i] = n - l[i];
    m[i] = l[i] - m[i];
  }

  // forward (bfs)
  s.clear();
  s[vs] = "";
  for (int i = 0; i < q / 2; ++i) {
    map<string, string> tmp;
    for (const auto& j: s) {
      for (int k = 0; k < p; ++k) {
        string v = j.first;
        rotate(v.begin(), v.begin() + m[k], v.begin() + l[k]);
        tmp[v] = j.second + (char)('1' + k);
      }
    }
    s.swap(tmp);
  }
  fprintf(stderr, "s.size() = %d\n", (int)s.size());

  // backward (dfs)
  for (int i = 0; i < p; ++i) {
    m[i] = l[i] - m[i];
  }
  try {
    dfs((q + 1) / 2, vt);
    puts("Impossible");
  } catch (string ans) {
    for (int i = 0; i < q; ++i) {
      printf("%c%c", ans[i], i == q - 1 ? '\n' : ' ');
    }
  }

  return 0;
}

