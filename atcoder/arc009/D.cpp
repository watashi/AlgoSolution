#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1000000007;
const int MAXN = 600;
const int MAXM = 600 * 80;

struct DisjointSet {
  int p[MAXN];

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return p[i] == i ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    if (i != j) {
      p[i] = j;
      return true;
    } else {
      return false;
    }
  }
};

inline int add(int a, int b) {
  return min(a + b, INF);
}

inline int mul(int a, int b) {
  return (int)min<long long>((long long)a * b, INF);
}

vector<pair<int, int> > gao(const vector<int>& v, const int w[MAXN][MAXN]) {
  int n = (int)v.size();
  vector<pair<int, pair<int, int> > > e;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (w[v[i]][v[j]] > 0) {
        e.push_back(make_pair(w[v[i]][v[j]], make_pair(i, j)));
      }
    }
  }

  int m = (int)e.size();
  bool p[MAXN];
  fill(p, p + m, false);
  fill(p, p + n - 1, true);
  sort(p, p + m);

  DisjointSet ds;
  int c[MAXN];
  fill(c, c + MAXN, 0);
  do {
    int sum = 0;
    ds.init(n);
    for (int i = 0; i < m; ++i) {
      if (p[i]) {
        if (ds.setp(e[i].second.first, e[i].second.second)) {
          sum += e[i].first;
        } else {
          sum = -1;
          break;
        }
      }
    }
    if (sum != -1) {
      ++c[sum];
    }
  } while (next_permutation(p, p + m));

  vector<pair<int, int> > ret;
  for (int i = 0; i < MAXN; ++i) {
    if (c[i] != 0) {
      ret.push_back(make_pair(i, c[i]));
    }
  }
  return ret;
}

vector<int> v[MAXN];
int e[MAXN][MAXN];

int main() {
  int r, n, q, m, a, b, c, s;

  scanf("%d%d%d", &r, &n, &q);
  for (int i = 0; i < r; ++i) {
    scanf("%d", &m);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a);
      --a;
      v[i].push_back(a);
    }
  }
  scanf("%d", &m);
  s = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    e[a][b] = e[b][a] = c;
    s += c;
  }

  vector<int> cur(MAXM, 0);
  cur[0] = 1;
  for (int i = 0; i < r; ++i) {
    vector<pair<int, int> > cc = gao(v[i], e);
    vector<int> pre(cur);
    fill(cur.begin(), cur.end(), 0);
    for (int j = 0; j < (int)pre.size(); ++j) {
      if (pre[j] == 0) {
        continue;
      }
      for (int k = 0; k < (int)cc.size() && j + cc[k].first < (int)cur.size(); ++k) {
        cur[j + cc[k].first] = add(cur[j + cc[k].first], mul(pre[j], cc[k].second));
      }
    }
  }

  for (int i = (int)cur.size() - 1; i >= 0; --i) {
    q -= cur[i];
    if (q <= 0) {
      printf("%d\n", s - i);
      break;
    }
  }
  if (q > 0) {
    puts("-1");
  }

  return 0;
}

