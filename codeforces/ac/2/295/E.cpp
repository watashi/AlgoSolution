#include <cstdio>
#include <algorithm>

using namespace std;

const long long BASE = 1LL << 32;

struct Triple {
  long long c, s, x;
};

const Triple ZERO = {0, 0, 0};

struct Node {
  long long l, r, m, c, s, x;
  Node *_pl, *_pr;

  Node(long long l, long long r):
      l(l), r(r), m((l + r) / 2), c(0), s(0), x(0), _pl(nullptr), _pr(nullptr) {
  }

  ~Node() {
    delete _pl;
    delete _pr;
  }

  bool isLeaf() const {
    return r - l == 1;
  }

  void add(long long i, long long d) {
   // printf("%I64d %I64d\n", l, r);
    c += d;
    s += d * i;
    if (!isLeaf()) {
      if (i < m) {
        if (_pl == nullptr) {
          _pl = new Node(l, m);
        }
        _pl->add(i, d);
      } else {
        if (_pr == nullptr) {
          _pr = new Node(m, r);
        }
        _pr->add(i, d);
      }
      x = (_pl == nullptr ? 0 : _pl->x) + (_pr == nullptr ? 0 : _pr->x);
      if (_pl != nullptr && _pr != nullptr) {
        x += _pl->c * _pr->s - _pr->c * _pl->s;
      }
    }
  }

  Triple query(long long l, long long r) {
    l = max(l, this->l);
    r = min(r, this->r);
    if (l >= r || c == 0) {
      return ZERO;
    } else if (l == this->l && r == this->r) {
      return {c, s, x};
    } else {
      Triple tl = _pl == nullptr ? ZERO : _pl->query(l, r);
      Triple tr = _pr == nullptr ? ZERO : _pr->query(l, r);
      return {tl.c + tr.c, tl.s + tr.s, tl.x + tr.x + tl.c * tr.s - tr.c * tl.s};
    }
  }
};

int main() {
  int n, m;
  long long t, l, r;
  vector<long long> x;
  Node *p;

  scanf("%d", &n);
  p = new Node(0, BASE + BASE);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &t);
    t += BASE;
    p->add(t, 1);
    x.push_back(t);
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%I64d%I64d%I64d", &t, &l, &r);
    if (t == 1) {
      --l;
      p->add(x[l], -1);
      x[l] += r;
      p->add(x[l], 1);
    } else {
      l += BASE;
      r += BASE;
      ++r;
      printf("%I64d\n", p->query(l, r).x);
    }
  }
  delete p;

  return 0;
}

