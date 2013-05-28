#include <map>
#include <cctype>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int ROOT = 0;
const int MAXN = 10001;

map<int, int> tab;
vector<int> e[MAXN];
int m[MAXN], u[MAXN], d[MAXN];
int depth, temp;
vector<int> ans;

int hashCode(int a, int b) {
  if (a <= b) {
    return a * 10000 + b;
  } else {
    return b * 10000 + a;
  }
}

void clear(int n) {
  tab.clear();
  for (int i = 0; i < n; ++i) {
    e[i].clear();
  }
  fill(m, m + n, 0);
  depth = 0;
  ans.clear();
}

void add(int a, int b, int c) {
  e[a].push_back(b);
  e[b].push_back(a);
  temp = hashCode(a, b);
  if (tab.count(temp) == 0) {
    tab[temp] = c;
  } else {
    tab[temp] = -1;
  }
}

void dfs(int p, int f) {
  d[p] = depth;
  u[p] = depth;
  m[p] = 1;
  ++depth;
  for (int i = 0; i < (int)e[p].size(); ++i) {
    int t = e[p][i];
    if ((t = e[p][i]) == f) {
      continue;
    }
    if (m[t] == 1) {
      u[p] = min(u[p], d[t]);
    } else if (m[t] == 0) {
      dfs(t, p);
      u[p] = min(u[p], u[t]);
      if (u[t] > d[p]) {
        temp = tab[hashCode(t, p)];
        if (temp != -1) {
          ans.push_back(temp);
        }
      }
    }
  }
  --depth;
  m[p] = 2;
}

void solve() {
  // !assert! connected
  dfs(ROOT, -1);
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < (int)ans.size(); i++) {
    printf("%d%c", ans[i], (i == (int)ans.size() - 1) ? '\n' : ' ');
  }
}

void nextInt(int& i) {
  static char ch = 0;

  while (!isdigit(ch = getchar())) {
    continue;
  }
  i = 0;
  do {
    i *= 10;
    i += ch - '0';
  } while (isdigit(ch = getchar()));
}

int main() {
  int n, m, a, b;

  freopen("bridges.in", "r", stdin);
  freopen("bridges.out", "w", stdout);
  nextInt(n);
  nextInt(m);
  clear(n);
  for (int i = 1; i <= m; i++) {
    nextInt(a);
    nextInt(b);
    add(a - 1, b - 1, i);
  }
  solve();

  return 0;
}

