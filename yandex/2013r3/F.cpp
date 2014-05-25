#include <cstdio>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

int main() {
  double x1, x2, y1, y2;
  double a1, r1, a2, r2;
  double ans;

  scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
  a1 = atan2(y1, x1);
  r1 = hypot(x1, y1);
  a2 = atan2(y2, x2);
  r2 = hypot(x2, y2);
  if (r1 > r2) {
    swap(a1, a2);
    swap(r1, r2);
  }
  a2 -= a1;
  r2 -= r1;
  a2 = fabs(a2);
  a2 = min(a2, 2 * PI - a2);
  a2 = min(a2, 2.0);
  ans = r2 + r1 * a2;
  printf("%.12lf\n", ans);

  return 0;
}
