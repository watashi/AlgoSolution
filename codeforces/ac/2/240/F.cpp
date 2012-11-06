#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const int SIGMA = 26;
const int MAXN = 100100;

void fillN(int n, int tag, const int c[SIGMA], int ret[SIGMA]) {
  assert(tag != 0);
  if (tag > 0) {
    for (int i = 0; i < SIGMA; ++i) {
      ret[i] = min(n, c[i]);
      n -= ret[i];
    }
  } else if (tag < 0) {
    for (int i = SIGMA - 1; i >= 0; --i) {
      ret[i] = min(n, c[i]);
      n -= ret[i];
    }
  }
}

struct Node {
  static Node NIL;
  const int l, r, m;
  int tag, c[SIGMA];
  Node *pl, *pr;

  Node(int l, int r): l(l), r(r), m((l + r) / 2), tag(0), pl(NULL), pr(NULL) {
    fill(c, c + SIGMA, 0);
  }

  Node(int l, int r, const char* p): l(l), r(r), m((l + r) / 2), tag(0), pl(NULL), pr(NULL) {
    if (size() > 1) {
      pl = new Node(l, m, p);
      pr = new Node(m, r, p);
      upd();
    } else {
      fill(c, c + SIGMA, 0);
      ++c[p[l] - 'a'];
    }
  }

  ~Node() {
    delete pl;
    delete pr;
  }

  int size() const {
    return r - l;
  }

  void upd() {
    for (int i = 0; i < SIGMA; ++i) {
      c[i] = pl->c[i] + pr->c[i];
    }
  }

  void dump() {
    if (tag != 0) {
      pl->tag = pr->tag = tag;
      fillN(pl->size(), tag, c, pl->c);
      tag = 0;
      for (int i = 0; i < SIGMA; ++i) {
        pr->c[i] = c[i] - pl->c[i];
      }
    }
  }

  void query(int ql, int qr, int qc[SIGMA]) {
    ql = max(ql, l);
    qr = min(qr, r);
    if (ql == l && qr == r) {
      for (int i = 0; i < SIGMA; ++i) {
        qc[i] += c[i];
      }
    } else if (ql < qr) {
      dump();
      pl->query(ql, qr, qc);
      pr->query(ql, qr, qc);
    }
  }

  void set(int ql, int qr, int qtag, int qc[SIGMA]) {
    ql = max(ql, l);
    qr = min(qr, r);
    if (ql == l && qr == r) {
      tag = qtag;
      fillN(size(), qtag, qc, c);
      for (int i = 0; i < SIGMA; ++i) {
        qc[i] -= c[i];
      }
    } else if (ql < qr) {
      dump();
      pl->set(ql, qr, qtag, qc);
      pr->set(ql, qr, qtag, qc);
      upd();
    }
  }

  void print() {
    if (size() == 1) {
      putchar('a' + (find(c, c + SIGMA, 1) - c));
    } else {
      dump();
      pl->print();
      pr->print();
    }
  }
};

int main() {
#ifndef __WATASHI__
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  Node* p;
  int n, m, l, r, t;
  static int c[SIGMA], cc[SIGMA];
  static char buf[MAXN];

  scanf("%d%d%s", &n, &m, buf);
  p = new Node(0, n, buf);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &l, &r);
    --l;
    fill(c, c + SIGMA, 0);
    p->query(l, r, c);
    if (count_if(c, c + SIGMA, [](int i) { return i % 2 != 0; }) > 1) {
      continue;
    }

    t = (r - l) / 2;
    if ((r - l) % 2 != 0) {
      for (int j = 0; j < SIGMA; ++j) {
        cc[j] = c[j] % 2;
      }
      p->set(l + t, l + t + 1, 1, cc);
    }
    for (int j = 0; j < SIGMA; ++j) {
      c[j] /= 2;
    }
    copy(c, c + SIGMA, cc);
    p->set(l, l + t, 1, cc);
    copy(c, c + SIGMA, cc);
    p->set(r - t, r, -1, cc);
  }
  p->print();

  return 0;
}
