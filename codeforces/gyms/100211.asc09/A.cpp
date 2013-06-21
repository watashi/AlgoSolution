#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, PII> PPP;
typedef vector<PII> VPII;

inline int sign(int x) {
  return x > 0 ? 1 : x < 0 ? -1 : 0;
}

int intersection(PII a, PII b, PII c, PII d) {
  if (a.first != b.first) {
    swap(a.first, a.second);
    swap(b.first, b.second);
    swap(c.first, c.second);
    swap(d.first, d.second);
  }
  if (a.second > b.second) {
    a.second = -a.second;
    b.second = -b.second;
    c.second = -c.second;
    d.second = -d.second;
  }
  if (c > d) {
    swap(c, d);
  }
  int ret;
  if (c.first > a.first || d.first < a.first) {
    ret = -1;
  } else if (min(c.second, d.second) > b.second || max(c.second, d.second) < a.second) {
    ret = -1;
  } else if (c.first == d.first) {
    ret = max(a.second, min(c.second, d.second)) - a.second;
  } else {
    ret = c.second - a.second;
  }
  //printf("(%d,%d)-(%d,%d) (%d,%d)-(%d,%d) @%d\n", a.first, a.second, b.first, b.second,
  //  c.first, c.second, d.first, d.second, ret);
  return ret;
}

bool sameside(PII a, PII b, PII c, PII d) {
  if (a.first != b.first) {
    swap(a.first, a.second);
    swap(b.first, b.second);
    swap(c.first, c.second);
    swap(d.first, d.second);
  }
  return ((c.first < a.first) ^ (d.first < a.first)) == 0;
}

PII point(const PII& a, const PII& b, int p) {
  int dx = sign(b.first - a.first);
  int dy = sign(b.second - a.second);
  return make_pair(a.first + p * dx, a.second + p * dy);
}

VPII path(const PII& a, const PII& b, const VPII& w, int u) {
  int i, t, k = 1, p = -1;
  VPII ret;
  // printf("[path] w.size() = %d\n", (int)w.size());
  for (i = 1; i < (int)w.size(); ++i) {
    t = intersection(a, b, w[i - 1], w[i]);
    if (t != -1 && (p == -1 || p > t)) {
      p = t;
      k = i;
    }
  }
  if (p != -1) {
    ret.push_back(point(a, b, p - u));
    if ((w[k - 1].first == w[k].first && w[k].first == ret.back().first) ||
      (w[k - 1].second == w[k].second && w[k].second == ret.back().second)) {
      ++k;
    }
    // printf("k = %d\n", k);
    for (i = k ; i < (int)w.size(); ++i) {
      ret.push_back(ret.back());
      if (i + 1 < (int)w.size() && sameside(w[i - 1], w[i], ret.back(), w[i + 1])) {
        if (w[i - 1].first == w[i].first) {
          ret.back().second = w[i].second - sign(w[i].second - w[i - 1].second) * u;
        } else {
          ret.back().first = w[i].first - sign(w[i].first - w[i - 1].first) * u;
        }
      } else {
        if (w[i - 1].first == w[i].first) {
          ret.back().second = w[i].second + sign(w[i].second - w[i - 1].second) * u;
        } else {
          ret.back().first = w[i].first + sign(w[i].first - w[i - 1].first) * u;
        }
      }
    }
  }
  return ret;
}

VPII trim(const VPII& v) {
  VPII ret;
  for (int i = 0; i < (int)v.size(); ++i) {
    if (ret.size() > 1) {
      if (ret.back().first == v[i].first && ret.back().first == (ret.end() - 2)->first) {
        ret.pop_back();
      } else if (ret.back().second == v[i].second && ret.back().second == (ret.end() - 2)->second) {
        ret.pop_back();
      }
    }
    if (ret.empty() || v[i] != ret.back()) {
      ret.push_back(v[i]);
    }
  }
  return ret;
}

VPII gao(const VPII& v, const VPII& w, int u) {
  int i, j;
  VPII p, q, r;
  for (i = 1; i < (int)v.size() && p.empty(); ++i) {
    // printf("i = %d\n", i);
    p = path(v[i - 1], v[i], w, u);
  }
  if (p.empty()) {
    return v;
  }
  for (j = (int)v.size() - 2; j >= 0 && q.empty(); --j) {
    // printf("j = %d\n", j);
    q = path(v[j + 1], v[j], w, u);
  }
  --i;
  ++j;
  // printf("i = %d; j = %d\n", i, j);
  r.insert(r.end(), v.begin(), v.begin() + i);
  r.insert(r.end(), p.begin(), p.end());
  r.insert(r.end(), q.rbegin(), q.rend());
  r.insert(r.end(), v.begin() + j + 1, v.end());
  return trim(r);
}

void output(int a, int b) {
  while (a % 2 == 0 && b % 2 == 0) {
    a /= 2;
    b /= 2;
  }
  printf("%d/%d", a, b);
}

int main() {
  int n, m, u, p[16];
  VPII v[16];

#ifndef __WATASHI__
  freopen("chip.in", "r", stdin);
  freopen("chip.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  m = 1 << (2 * n); // if m = 1 << n then WA
  for (int i = 0; i < n; ++i) {
    u = 1 << (2 * (n - 1 - i));
    v[i].clear();
    v[i].push_back(make_pair(i * m, 0));
    if (i != p[i]) {
      v[i].push_back(make_pair(i * m, m / 2));
      v[i].push_back(make_pair(p[i] * m, m / 2));
    }
    v[i].push_back(make_pair(p[i] * m, m));
    for (int j = 0; j < i; ++j) {
      v[i] = gao(v[i], v[j], u);
    }
  }

  for (int i = 0; i < n; ++i) {
    printf("%d\n", (int)v[i].size() - 1);
    for (int j = 0; j < (int)v[i].size(); ++j) {
      output(v[i][j].first, m);
      putchar(' ');
      output(v[i][j].second, m);
      putchar('\n');
    }
  }
  puts("");

  return 0;
}

