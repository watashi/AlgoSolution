#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Op {
  int l, r, d;
};

int main() {
  int n, m, k, l, r, d;
  vector<long long> a, b, c;
  vector<Op> op;

  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d);
    a.push_back(d);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &l, &r, &d);
    op.push_back({l - 1, r, d});
  }

  vector<long long>(m + 1, 0).swap(b);
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", &l, &r);
    ++b[l - 1];
    --b[r];
  }
  partial_sum(b.begin(), b.end(), b.begin());

  vector<long long>(n + 1, 0).swap(c);
  for (int i = 0; i < m; ++i) {
    if (b[i] != 0) {
      c[op[i].l] += op[i].d * b[i];
      c[op[i].r] -= op[i].d * b[i];
    }
  }
  partial_sum(c.begin(), c.end(), c.begin());

  for (int i = 0; i < n; ++i) {
    printf("%I64d ", a[i] + c[i]);
  }

  return 0;
}

