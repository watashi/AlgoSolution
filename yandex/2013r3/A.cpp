#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;

double fact[MAXN];
double cnt[MAXN], dp[MAXN];

void init() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = fact[i - 1] * i;
  }
}

int main() {
  int n;
  double a, ans;
  vector<double> good, bad;

  init();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &a);
    if (a >= 0) {
      good.push_back(a);
    } else {
      bad.push_back(a);
    }
  }

  if (bad.empty()) {
    ans = accumulate(good.begin(), good.end(), 0.0);
  } else {
    fill(cnt, cnt + MAXN, 0);
    fill(dp, dp + MAXN, 0);
    cnt[0] = 1;
    for (double i: good) {
      for (int j = MAXN - 1; j >= 1; --j) {
        cnt[j] += cnt[j - 1];
        dp[j] += dp[j - 1] + i * cnt[j - 1];
      }
    }
    ans = 0;
    for (int i = 0; i < n; ++i) {
      // printf("[%d] %lf %lf\n", i, cnt[i], dp[i]);
      for (double j: bad) {
        ans += (dp[i] + j * cnt[i]) * fact[i] * fact[n - 1 - i];
      }
    }
    ans /= fact[n];
  }
  printf("%.12lf\n", ans);

  return 0;
}

