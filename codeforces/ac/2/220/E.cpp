#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  vector<int> v;
  Node *pl, *pr;

  Node(int n, const int a[]): v(n), pl(NULL), pr(NULL) {
    if (n == 1) {
      v[0] = a[0];
    } else {
      int m = n / 2;
      pl = new Node(m, a);
      pr = new Node(n - m, a + m);
      merge(pl->v.begin(), pl->v.end(), pr->v.begin(), pr->v.end(), v.begin());
    }
  }

  ~Node() {
    delete pl;
    delete pr;
  }

  int size() const {
    return v.size();
  }

  int clt(int x) const {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  }

  int ceq(int x) const {
    auto r = equal_range(v.begin(), v.end(), x);
    return r.second - r.first;
  }

  int cgt(int x) const {
    return v.end() - upper_bound(v.begin(), v.end(), x);
  }

  template<typename T>
  int cf(int l, int r, int x, T f) const {
    l = max(0, l);
    r = min(r, size());
    if (l >= r) {
      return 0;
    } else if (l == 0 && r == size()) {
      return f(this, x);
    } else {
      return pl->cf(l, r, x, f) + pr->cf(l - pl->size(), r - pl->size(), x, f);
    }
  }

  int clt(int l, int r, int x) const {
    return cf(l, r, x, [](const Node* self, int x){ return self->clt(x); });
  }

  int ceq(int l, int r, int x) const {
    return cf(l, r, x, [](const Node* self, int x){ return self->ceq(x); });
  }

  int cgt(int l, int r, int x) const {
    return cf(l, r, x, [](const Node* self, int x){ return self->cgt(x); });
  }
};

const int MAXN = 100100;
int a[MAXN];

int main() {
  int n;
  Node* p;
  long long m, s;

  scanf("%d", &n);
  scanf("%I64d", &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  p = new Node(n, a);

  for (int i = 1; i < n; ++i) {
    m -= p->clt(i + 1, n, a[i]);
  }
  s = 0;
  for (int i = 0, j = 1; i < n && j < n; ++i) {
    m -= p->cgt(0, i, a[i]);
    m -= p->clt(j, n, a[i]);
    // printf("@%d = %I64d\n", i, m);
    while (j < n && (j <= i || m < 0)) {
      m += p->cgt(0, i + 1, a[j]);
      m += p->clt(j, n, a[j]);
      ++j;
    }
    // printf("[%d, %d] = %I64d\n", i, j, m);
    s += n - j;
  }
  printf("%I64d\n", s);
  delete p;

  return 0;
}

