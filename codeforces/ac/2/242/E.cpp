#include <cstdio>
#include <algorithm>

using namespace std;

const int BITS = 20;
const int MAXN = 100100;

bool test(int i, int j) {
  return (i >> j) & 1;
}

struct Node {
  const int pl, pr, pm;
  int tag, c[BITS];
  Node *bl, *br;

  Node(int pl, int pr, const int a[]): pl(pl), pr(pr), pm((pl + pr) / 2), tag(0) {
    if (size() == 1) {
      bl = br = nullptr;
      fill(c, c + BITS, 0);
      for (int i = 0; i < BITS; ++i) {
        if (test(a[pl], i)) {
          ++c[i];
        }
      }
    } else {
      bl = new Node(pl, pm, a);
      br = new Node(pm, pr, a);
      lift();
    }
  }

  ~Node() {
    delete bl;
    delete br;
  }

  int size() const {
    return pr - pl;
  }

  long long sum() {
    long long ret = 0;
    dump();
    for (int i = BITS - 1; i >= 0; --i) {
      ret = ret * 2 + c[i];
    }
    return ret;
  }

  void lift() {
    bl->dump();
    br->dump();
    for (int i = 0; i < BITS; ++i) {
      c[i] = bl->c[i] + br->c[i];
    }
  }

  void dump() {
    if (tag == 0) {
      return;
    }
    if (size() > 1) {
      bl->tag ^= tag;
      br->tag ^= tag;
    }
    for (int i = 0; i < BITS; ++i) {
      if (test(tag, i)) {
        c[i] = size() - c[i];
      }
    }
    tag = 0;
  }

  void update(int l, int r, int x) {
    l = max(l, pl);
    r = min(r, pr);
    if (l >= r) {
      return;
    } else if (l == pl && r == pr) {
      tag ^= x;
    } else {
      dump();
      bl->update(l, r, x);
      br->update(l, r, x);
      lift();
    }
  }

  long long query(int l, int r) {
    l = max(l, pl);
    r = min(r, pr);
    if (l >= r) {
      return 0;
    } else if (l == pl && r == pr) {
      return sum();
    } else {
      dump();
      return bl->query(l, r) + br->query(l, r);
    }
  }
};

int a[MAXN];

int main() {
  int n, m, l, r, x;
  Node* p;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  p = new Node(0, n, a);

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &x, &l, &r);
    --l;
    if (x == 1) {
      printf("%I64d\n", p->query(l, r));
    } else {
      scanf("%d", &x);
      p->update(l, r, x);
    }
  }
  delete p;

  return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//2541057 	Nov 12, 2012 2:10:36 AM 	watashi 	E - XOR on Segment 	GNU C++0x 	Accepted 	656 ms 	22320 KB

