#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 505;

bool mark[MAXN];
int a[MAXN][MAXN], w[MAXN][MAXN];

int main() {
  int n;
  vector<int> v;
  vector<long long> ans;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  v.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    --v[i];
  }
  reverse(v.begin(), v.end());

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      w[i][j] = a[v[i]][v[j]];
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
      }
    }
    long long tmp = 0;
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j <= k; ++j) {
        tmp += w[i][j];
      }
    }
    ans.push_back(tmp);
  }

  reverse(ans.begin(), ans.end());
  for (long long i: ans) {
    printf("%I64d ", i);
  }

  return 0;
}

