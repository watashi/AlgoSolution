#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10101;

int n, b;
int s[MAXN];
vector<int> c, e[MAXN];

int dfs(int p) {
  s[p] = 1;
  for (size_t i = 0; i < e[p].size(); ++i) {
    if (s[e[p][i]] == 0) {
      s[p] += dfs(e[p][i]);
    }
  }
  return s[p];
}

void dfs(int p, int r) {
  // assert(r < 0);
  s[p] = r;
  for (size_t i = 0; i < e[p].size(); ++i) {
    if (s[e[p][i]] > 0) {
      dfs(e[p][i], r);
    }
  }
}

int gao(int p, int r) {
  int ret = -1;
  queue<pair<int, int> > q;
  vector<pair<int, int> > v;

  // assert(r < b);
  // assert(s[p] >= b);
  // printf("gao %d\n", p);
  s[p] = 0;
  if (r > 0) {
    v.push_back(make_pair(r, -1));
  }
  for (size_t i = 0; i < e[p].size(); ++i) {
    if (s[e[p][i]] > 0) {
      v.push_back(make_pair(s[e[p][i]], e[p][i]));
    }
  }
  sort(v.begin(), v.end());

  int pos = 0, sum = 0;

  // puts("A");
  while (pos < (int)v.size() && v[pos].first < b) {
    sum += v[pos].first;
    q.push(v[pos]);
    if (sum >= 3 * b) {
      c.push_back(p);
      do {
        sum -= q.front().first;
        if (q.front().second == -1) {
          ret = -c.size();
        } else {
          dfs(q.front().second, -c.size());
        }
        q.pop();
      } while (sum > 2 * b);
      // sum \in [b, 2b]
    }
    ++pos;
  }
  // puts("B");
  if (sum + 1 < b) {
    // assert(pos != (int)v.size());
    r = sum + 1;
    v.back().first += r;
  } else {
    r = 0;
    c.push_back(p);
    s[p] = -c.size();
  }
  // puts("C");
  while (pos < (int)v.size()) {
    if (r > 0 && pos == (int)v.size() - 1) {
      if (v[pos].first > 3 * b) {
        s[p] = gao(v[pos].second, r);
      } else {
        c.push_back(p);
        dfs(v[pos].second, -c.size());
        s[p] = -c.size();
      }
    } else if (v[pos].first > 3 * b) {
      gao(v[pos].second, 0);
    } else {
      c.push_back(p);
      dfs(v[pos].second, -c.size());
    }
    ++pos;
  }
  // puts("D");
  while (!q.empty()) {
    if (q.front().second == -1) {
      ret = s[p];
    } else {
      dfs(q.front().second, s[p]);
    }
    q.pop();
  }

  return ret;
}

int main() {
  int x, y;

  freopen("royal.in", "r", stdin);
  freopen("royal.out", "w", stdout);
  scanf("%d%d", &n, &b);
  for (int i = 1; i <= n; ++i) {
    s[i] = 0;
    e[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1);
  c.clear();
  gao(1, 0);
  printf("%d\n", (int)c.size());
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", -s[i], (i == n) ? '\n' : ' ');
  }
  for (size_t i = 0; i < c.size(); ++i) {
    printf("%d%c", c[i], (i == c.size() - 1) ? '\n' : ' ');
  }

  return 0;
}

