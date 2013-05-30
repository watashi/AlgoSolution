#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 128;

struct BigInteger : public vector<long long> {
  static const int MOD = 1000000000;

  BigInteger(long long i) : vector<long long>(1, i) {
  }

  BigInteger& operator*=(long long i) {
    long long c = 0;
    for (iterator it = begin(); it != end(); ++it) {
      *it = *it * i + c;
      c = *it / MOD;
      *it %= MOD;
    }
    if (c > 0) {
      push_back(c);
    }
    return *this;
  }
};

struct Polynomial : public vector<int> {
  static int r;

  int operator()(int x) const {
    int ret = 0;

    for (const_reverse_iterator it = rbegin(); it != rend(); ++it) {
      ret *= x;
      ret += *it;
      ret %= r;
    }

    return ret;
  }
};

int Polynomial::r;

Polynomial readPolynomial() {
  int n;
  Polynomial ret;

  scanf("%d", &n);
  ret.resize(n + 1);
  for (int i = n; i >= 0; --i) {
    scanf("%d", &ret[i]);
  }

  return ret;
}

void writeBigInteger(const BigInteger& b) {
  for (BigInteger::const_reverse_iterator i = b.rbegin(); i != b.rend(); ++i) {
    printf("%0*lld", i == b.rbegin() ? 0 : 9, *i);
  }
  puts("");
}

void gao(vector<int>& p) {
  vector<int> w(p.size(), 0);
  for (int i = 0; i < (int)p.size(); ++i) {
    if (w[i] != 0) {
      continue;
    }
    vector<int> s;
    w[i] = -1;
    s.push_back(i);
    while (w[p[s.back()]] == 0) {
      w[p[s.back()]] = -1;
      s.push_back(p[s.back()]);
    }
    if (w[p[s.back()]] == -1) {
      int t = p[s.back()];
      while (s.back() != t) {
        w[s.back()] = 1;
        s.pop_back();
      }
      w[t] = 1;
      s.pop_back();
    }
    while (!s.empty()) {
      p[s.back()] = -1;
      w[s.back()] = 1;
      s.pop_back();
    }
  }
}

int main() {
#ifndef __WATASHI__
  freopen("stable.in", "r", stdin);
  freopen("stable.out", "w", stdout);
#endif
  scanf("%d", &Polynomial::r);

  Polynomial p = readPolynomial();
  Polynomial q = readPolynomial();
  vector<vector<int> > v(2, vector<int>(Polynomial::r));
  for (int i = 0; i < Polynomial::r; ++i) {
    v[0][i] = p(i);
    v[1][i] = q(i);
  }
  gao(v[0]);
  gao(v[1]);

  BigInteger ans(1);
  vector<int> w(Polynomial::r, 0);
  for (int i = 0; i < Polynomial::r; ++i) {
    if (v[0][i] == -1 || v[1][i] == -1) {
      w[i] = -1;
    }
  }
  for (int i = 0; i < Polynomial::r; ++i) {
    if (w[i] != 0) {
      continue;
    }
    vector<int> q(1, i);
    for (int j = 0; j < (int)q.size(); ++j) {
      switch (w[v[0][q[j]]]) {
      case -1: goto NEXT;
      case 0: q.push_back(v[0][q[j]]);
      default: w[v[0][q[j]]] |= 1;
      }
      switch (w[v[1][q[j]]]) {
      case -1: goto NEXT;
      case 0: q.push_back(v[1][q[j]]);
      default: w[v[1][q[j]]] |= 2;
      }
    }
    ans *= 2;
NEXT:
    for (int j = 0; j < (int)q.size(); ++j) {
      w[q[j]] = -1;
    }
  }

  writeBigInteger(ans);

  return 0;
}


