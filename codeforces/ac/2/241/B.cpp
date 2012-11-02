#include <cstdio>
#include <memory>
#include <algorithm>

using namespace std;

const int BITLEN = 30;
const int MAXN = 65536;
const int MOD = 1000000007;

int bit(int i, int j) {
  return (i >> j) & 1;
}

struct Trie {
  static Trie* const NIL;
  const int pos;
  int num, cnt[BITLEN];
  long long sum;
  Trie* sub[2];

  Trie(int pos): pos(pos), num(0), sum(0) {
    fill(cnt, cnt + BITLEN, 0);
    fill(sub, sub + 2, NIL);
  }

  ~Trie() {
    for (int i = 0; i < 2; ++i) {
      if (sub[i] != NIL) {
        delete sub[i];
      }
    }
  }

  void insert(int x) {
    ++num;
    sum += x;
    for (int i = 0; i < BITLEN; ++i) {
      if (bit(x, i) == 0) {
        ++cnt[i];
      } else {
        --cnt[i];
      }
    }
    if (pos >= 0) {
      Trie* &p = sub[bit(x, pos)];
      if (p == NIL) {
        p = new Trie(pos - 1);
      }
      p->insert(x);
    }
  }

  // length [i | i ^ x >= y]
  int count(int x, int y) const {
    if (pos < 0 || num == 0) {
      return num;
    } else if (bit(y, pos) == 1) {
      return sub[bit(x, pos) ^ 1]->count(x, y);
    } else {
      return sub[bit(x, pos) ^ 1]->num + sub[bit(x, pos)]->count(x, y);
    }
  }

  // sum [i ^ x]
  long long _total(int x) const {
    long long ret = sum;
    for (int i = 0; i < BITLEN; ++i) {
      if (bit(x, i) == 1) {
        ret += (long long)cnt[i] << i;
      }
    }
    return ret;
  }

  // sum [i | i ^ x >= y]
  long long total(int x, int y) const {
    if (pos < 0 || num == 0) {
      return _total(x);
    } else if (bit(y, pos) == 1) {
      return sub[bit(x, pos) ^ 1]->total(x, y);
    } else {
      return sub[bit(x, pos) ^ 1]->_total(x) + sub[bit(x, pos)]->total(x, y);
    }
  }
};

Trie* const Trie::NIL = new Trie(-BITLEN);

int main() {
  int n, m;
  long long num, sum;
  static int a[MAXN];
  unique_ptr<Trie> p(new Trie(BITLEN - 1));

  scanf("%d%d", &n, &m);
  num = 2LL * m;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    p->insert(a[i]);
  }

  int l = 0, r = 1 << 30; // r = MOD => WA25
  while (l < r) {
    long long tmp = 0;
    m = (l + r) / 2;
    for (int i = 0; i < n && tmp < num; ++i) {
      tmp += p->count(a[i], m);
    }
    if (tmp >= num) {
      l = m + 1;
    } else {
      r = m;
    }
  }

  m = r - 1;
  sum = 0;
  for (int i = 0; i < n; ++i) {
    num -= p->count(a[i], m);
    sum += p->total(a[i], m);
  }
  sum += num * m;
  sum /= 2;
  printf("%d\n", (int)(sum % MOD));

  return 0;
}

