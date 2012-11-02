#include <queue>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 50005;
const int THRESHOLD = 64;

void yes(const vector<int>& ans) {
  puts("Yes");
  printf("%d\n", (int)ans.size());
  for (int i: ans) {
    printf("%d ", i + 1);
  }
}

void gaoSmall(int n, int m, const int a[], const int t[]) {
  static int dp[THRESHOLD][MAXN];
  static int pre[THRESHOLD][MAXN];
  priority_queue<pair<int, pair<int, int> > > pq;

  fill(dp[0], dp[THRESHOLD], n);
  dp[0][0] = -1;
  pq.push(make_pair(-dp[0][0], make_pair(0, 0)));
  while (!pq.empty()) {
    int d, ixor, imod;
    d = -pq.top().first;
    tie(ixor, imod) = pq.top().second;
    pq.pop();
    if (dp[ixor][imod] < d) {
      continue;
    }
    for (int j = d + 1; j < n; ++j) {
      int jxor = ixor ^ a[j];
      int jmod = (1LL * imod * t[j] + a[j]) % m;
      if (jxor == 0 && jmod == 0) {
        vector<int> ans;
        ans.push_back(j);
        while (ixor != 0 || imod != 0) {
          int i = dp[ixor][imod];
          ans.push_back(i);
          imod = pre[ixor][imod];
          ixor ^= a[i];
        }
        reverse(ans.begin(), ans.end());
        return yes(ans);
      } if (dp[jxor][jmod] > j) {
        dp[jxor][jmod] = j;
        pre[jxor][jmod] = imod;
        pq.push(make_pair(-j, make_pair(jxor, jmod)));
      }
    }
  }
  puts("No");
}

void gaoLarge(int n, int m, const int a[], const int t[]) {
  static int p[MAXN];

  p[0] = -1;
  for (int i = 0; i < n; ++i) {
    p[a[i]] = i;
  }
  while (true) {
    int ixor = 0;
    long long imod = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      int r = 2;
      if (ixor <= n && p[ixor] >= i && (imod * t[p[ixor]] + ixor) % m == 0) {
        i = p[ixor];
        r = 1;
      }
      if (rand() % r == 0) {
        ans.push_back(i);
        ixor = ixor ^ a[i];
        imod = (imod * t[i] + a[i]) % m;
        if (ixor == 0 && imod == 0) {
          return yes(ans);
        }
      }
    }
  }
}

int main() {
  int n, m, a[MAXN], t[MAXN];

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    t[i] = 10;
    while (t[i] <= a[i]) {
      t[i] *= 10;
    }
  }
  if (n < THRESHOLD) {
    gaoSmall(n, m, a, t);
  } else {
    gaoLarge(n, m, a, t);
  }

  return 0;
}
