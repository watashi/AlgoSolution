#include <deque>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n;
  int64_t x, y, t, p;
  deque<int64_t> q;

  scanf("%lld / %lld", &x, &y);
  y *= 1000000000;
  scanf("%d", &n);
  p = -y;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &t);
    while (!q.empty() && q.front() < t - y) {
      p = q.front();
      q.pop_front();
    }
    while (q.size() >= x) {
      p = q.front();
      q.pop_front();
    }
    t = max(t, p + y);
    q.push_back(t);
    printf("%lld ", t);
  }
  puts("");

  return 0;
}
