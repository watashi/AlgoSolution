#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long c[20][200];
long long s[20][200];
long long o[200][20];
long long x[200][20];

void init() {
  c[0][0] = o[0][0] = 1LL;
  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j < 200; ++j) {
      for (int k = 0; k < 10 && k <= j; ++k) {
        c[i][j] += c[i - 1][j - k];
      }
      o[j][i] = c[i][j];
    }
  }
  for (int i = 0; i < 20; ++i) {
    partial_sum(c[i], c[i + 1] - 1, s[i] + 1);
  }
  for (int j = 0; j < 200; ++j) {
    partial_sum(o[j], o[j + 1] - 1, x[j] + 1);
  }
}

vector<int> digits(long long n) {
  vector<int> ret;
  while (n > 0) {
    ret.push_back(n % 10);
    n /= 10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int digitsum(long long n) {
  vector<int> d = digits(n);
  return accumulate(d.begin(), d.end(), 0);
}

long long sum_less(int s, const vector<int>& d) {
  long long ret = ::s[d.size() - 1][s] - 1;
  for (int i = 0; i < (int)d.size(); ++i) {
    for (int j = (i == 0 ? 1 : 0); j < d[i]; ++j) {
      if (s >= j) {
        ret += ::s[d.size() - i - 1][s - j];
      }
    }
    s -= d[i];
  }
  return ret;
}

long long lex_less(int s, const vector<int>& k, const vector<int>& d) {
  int x;
  long long ret = 0;

  // length <
  x = s;
  for (int i = 0; i < (int)k.size(); ++i) {
    if (x == 0) {	// prefix
      ++ret;
    }
    for (int j = (i == 0 ? 1 : 0); j < k[i]; ++j) {
      if (x >= j) {
        ret += ::x[x - j][d.size() - i - 1];
      }
    }
    x -= k[i];
  }

  // length ==
  if (k < d) {
    x = s;
    for (int i = 0; i < (int)k.size(); ++i) {
      for (int j = (i == 0 ? 1 : 0); j < k[i]; ++j) {
        if (x >= j) {
          ret += ::o[x - j][d.size() - i - 1];
        }
      }
      x -= k[i];
    }
  } else {
    x = s;
    for (int i = 0; i < (int)d.size(); ++i) {
      for (int j = (i == 0 ? 1 : 0); j < d[i]; ++j) {
        if (x >= j) {
          ret += ::o[x - j][d.size() - i - 1];
        }
      }
      x -= d[i];
    }
  }

  return ret;
}

int main() {
  int ds, l, r, m;
  long long n, k;
  vector<int> dn, dk;

  init();
/*
  n = 1024;
  vector<long long> ans(n, -1);
  for (int i = 1; i <= n; ++i) {
    long long idx = sum_less(digitsum(i), digits(n + 1)) + lex_less(digitsum(i), digits(i), digits(n + 1));
    if (ans[idx] != -1) {
      printf("ERROR: [%4lld] = %-4lld (%d) [%d]\n", idx, ans[idx], digitsum(ans[idx]), i);
    }
    ans[idx] = i;
  }
  for (int i = 0; i < n; ++i) {
    printf("[%4d] = %-4lld (%d)\n", i, ans[i], digitsum(ans[i]));
  }
*/

#ifndef __WATASHI__
  freopen("grlex.in", "r", stdin);
  freopen("grlex.out", "w", stdout);
#endif
  scanf("%lld%lld", &n, &k);
  ds = digitsum(k);
  dn = digits(n + 1);
  dk = digits(k);
  printf("%lld\n", 1 + sum_less(ds, dn) + lex_less(ds, dk, dn));

  l = 0;
  r = 200;
  while (l < r) {
    m = (l + r) / 2;
    if (sum_less(m, dn) < k) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  m = r - 1;

  k -= sum_less(m, dn);
  dk.clear();
  while (dk.size() <= dn.size()) {
    dk.push_back(9);
    while (dk.back() >= 0 && lex_less(m, dk, dn) >= k) {
      --dk.back();
    }
    if (dk.back() == -1) {
      break;
    }
  }
  dk.pop_back();

  for (int i = 0; i < (int)dk.size(); ++i) {
    printf("%d", dk[i]);
  }
  puts("");

  return 0;
}


