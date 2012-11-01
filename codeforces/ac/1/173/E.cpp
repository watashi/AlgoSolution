#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

vector<int> remap(int n, int a[]) {
  vector<int> ret;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[a[i]];
  }
  for (auto& i: mp) {
    i.second = ret.size();
    ret.push_back(i.first);
  }
  for (int i = 0; i < n; ++i) {
    a[i] = mp[a[i]];
  }
  return ret;
}

typedef int bin_op(int, int);

struct SegTree {
  int n, s[MAXN + MAXN];
  bin_op* f;

  static int L(int i) { return i << 1; }
  static int R(int i) { return L(i) ^ 1; }

  static int sum(int i, int j) { return i + j; }
  static int max(int i, int j) { return std::max(i, j); }

  void init(int m, bin_op* g) {
    f = g;
    n = 1;
    while (n < m) {
      n <<= 1;
    }
    fill(s, s + n + n, 0);
  }

  void update(int i, int j) {
    i += n;
    while (i > 0) {
      s[i] = f(s[i], j);
      i >>= 1;
    }
  }

  int query(int p, int pl, int pr, int l, int r) {
    l = max(l, pl);
    r = min(r, pr);
    if (l >= r) {
      return 0;
    } else if (l == pl && r == pr) {
      return s[p];
    } else {
      int pm = (pl + pr) / 2;
      return f(query(L(p), pl, pm, l, r), query(R(p), pm, pr, l, r));
    }
  }

  int query(int l, int r) {
    return query(1, 0, n, l, r);
  }
} st;

int main() {
  int n, k, m, x, y;
  vector<int> vr, va;
  static int r[MAXN], a[MAXN];

  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &r[i]);
  }
  vr = remap(n, r);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  va = remap(n, a);

  vector<vector<int> > v(va.size());
  vector<pair<int, pair<int, int> > > w;

  for (int i = 0; i < n; ++i) {
    v[a[i]].push_back(r[i]);
  }
  st.init(vr.size(), SegTree::sum);
  for (int i = 0, l = 0, r = 0; i < (int)v.size(); ++i) {
    while (r < (int)v.size() && va[r] - va[i] <= k) {
      for (int j: v[r]) {
        st.update(j, 1);
      }
      ++r;
    }
    while (va[i] - va[l] > k) {
      for (int j: v[l]) {
        st.update(j, -1);
      }
      ++l;
    }
    int rr = *max_element(v[i].begin(), v[i].end());
    // printf("[%d, %d, %d]\n", vr[rr], va[i], st.query(0, rr + 1));
    w.push_back(make_pair(rr, make_pair(i, st.query(0, rr + 1))));
  }
  sort(w.begin(), w.end());

  vector<pair<pair<int, int>, pair<int, int> > > q;

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    --x;
    --y;
    if (a[x] > a[y]) {
      swap(x, y);
    }
    q.push_back(make_pair(
        make_pair(max(r[x], r[y]), i),
        make_pair(
          lower_bound(va.begin(), va.end(), va[a[y]] - k) - va.begin(),
          upper_bound(va.begin(), va.end(), va[a[x]] + k) - va.begin())));
  }

  st.init(va.size(), SegTree::max);
  sort(q.rbegin(), q.rend());
  for (auto& i: q) {
    while (!w.empty() && w.back().first >= i.first.first) {
      st.update(w.back().second.first, w.back().second.second);
      w.pop_back();
    }
    i.first.first = st.query(i.second.first, i.second.second);
    swap(i.first.first, i.first.second);
  }
  sort(q.begin(), q.end());
  for (auto& i: q) {
    printf("%d\n", i.first.second >= 2 ? i.first.second : -1);
  }

  return 0;
}

