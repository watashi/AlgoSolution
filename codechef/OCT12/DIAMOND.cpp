#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2012;

vector<double> a[MAXN];

int main() {
  a[1].push_back(1.0);
  for (int i = 2; i < MAXN; ++i) {
    a[i].resize(i);
    // head
    a[i][0] += 1;
    for (int j = 0; j < i - 1; ++j) {
      a[i][j + 1] += 1.0 - a[i - 1][j];
    }
    // tail
    a[i][i - 1] += 1;
    for (int j = 0; j < i - 1; ++j) {
      a[i][j] += 1.0 - a[i - 1][j];
    }
    // half
    for (int j = 0; j < i; ++j) {
      a[i][j] /= 2.0;
    }
  }

  int re, n;
  double v, ans;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d", &n);
    ans = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%lf", &v);
      ans += a[n][i] * v;
    }
    printf("%.3lf\n", ans);
  }

  return 0;
}

//Correct Answer
//Execution Time: 8.48

