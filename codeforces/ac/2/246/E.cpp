#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

template<typename T>
int getId(map<T, int>& mp, const T& key) {
  int ret = 0;
  if (mp.count(key) == 0) {
    ret = mp.size();
    mp[key] = ret;
  } else {
    ret = mp[key];
  }
  return ret;
}

struct P {
  int depth, begin, end, name;
  vector<int> e;
} p[MAXN];

void dfs(int v, int d, int& s) {
  p[v].depth = d;
  if (p[v].e.empty()) {
    p[v].begin = s;
    p[v].end = s + 1;
    ++s;
  } else {
    for (int w: p[v].e) {
      dfs(w, d + 1, s);
    }
    p[v].begin = p[p[v].e.front()].begin;
    p[v].end = p[p[v].e.back()].end;
  }
  // printf("#%d: %d [%d %d) %d\n", v, p[v].depth, p[v].begin, p[v].end, p[v].name);
}

struct SegmentTree {
  int n, a[MAXN + MAXN];

  static int L(int i) { return i << 1; }
  static int R(int i) { return L(i) ^ 1; }

  void init(int m) {
    n = 1;
    while (n < m) {
      n <<= 1;
    }
    fill(a, a + n + n, 0);
  }

  void incr(int i) {
    i += n;
    while (i > 0) {
      ++a[i];
      i >>= 1;
    }
  }

  int count(int p, int pl, int pr, int l, int r) {
    l = max(pl, l);
    r = min(pr, r);
    if (l >= r) {
      return 0;
    } else if (l == pl && r == pr) {
      return a[p];
    } else {
      int pm = (pl + pr) >> 1;
      return count(L(p), pl, pm, l, r) + count(R(p), pm, pr, l, r);
    }
  }

  int count(int l, int r) {
    return count(1, 0, n, l, r);
  }
} st;

int ans[MAXN];

void gao (int s, vector<int>& ps, vector<pair<pair<int, int>, int> >& qs) {
  int n = ps.size();
  map<int, int> next;
  map<int, int> first;

  sort(ps.begin(), ps.end(), [&](int i, int j) { return p[i].begin < p[j].begin; });
  sort(qs.begin(), qs.end());
  for (int i = n - 1; i >= 0; --i) {
    const P& p = ::p[ps[i]];
    if (first.count(p.name) > 0) {
      next[p.begin] = first[p.name];
    }
    first[p.name] = p.begin;
    // printf(" (%d)<%d, %d> ", ps[i], p.name, p.begin);
  }
  // puts("");

  st.init(s);
  for (auto& i: first) {
    // printf(" +incr %d\n", i.second);
    st.incr(i.second);
  }

  reverse(ps.begin(), ps.end());
  for (auto q: qs) {
    int begin, end;
    tie(begin, end) = q.first;
    // printf("Q%d: [%d, %d)\n", q.second, begin, end);
    while (!ps.empty() && p[ps.back()].begin < begin) {
      if (next.count(p[ps.back()].begin) > 0) {
        st.incr(next[p[ps.back()].begin]);
      }
      ps.pop_back();
    }
    ans[q.second] = st.count(begin, end);
  }
}

int main() {
  int n, m, v, k, s;
  char buf[4096];
  map<string, int> mp;
  map<int, vector<int> > ps;
  map<int, vector<pair<pair<int, int>, int> > > qs;

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s%d", buf, &k);
    p[i].name = getId<string>(mp, buf);
    p[k].e.push_back(i);
  }

  s = 0;
  dfs(0, 0, s);
  for (int i = 1; i <= n; ++i) {
    ps[p[i].depth].push_back(i);
  }

  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &v, &k);
    qs[p[v].depth + k].push_back({{p[v].begin, p[v].end}, i});
  }

  for (int i = 1; i <= n; ++i) {
    if (ps.count(i) > 0 && qs.count(i) > 0) {
      // printf("GAO %d\n", i);
      gao(s, ps[i], qs[i]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", ans[i]);
  }

  return 0;
}

