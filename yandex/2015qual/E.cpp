#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int64_t> gao(int64_t n) {
  vector<int64_t> v, w;
  for (int64_t i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      v.push_back(i);
      if (i * i != n) {
        w.push_back(n / i);
      }
    }
  }
  v.insert(v.end(), w.rbegin(), w.rend());
  return v;
}

int main() {
  int64_t n, m, x, y;
  cin >> n >> m >> x >> y;
  --x;

  vector<int64_t> a = gao(n);
  vector<int64_t> b = gao(m);

  int64_t ans = 0;
  for (int64_t i: a) {
    ans += upper_bound(b.begin(), b.end(), y / i)
         - upper_bound(b.begin(), b.end(), x / i);
  }
  cout << ans << endl;

  return 0;
}
