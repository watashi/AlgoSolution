#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int z, na, nb;
  char c[256], sa[4004], sb[4004];
  map<char, int> alphabet;
  int dist[256][256];
  int mina[256], minb[256];
  int a[2002], b[2002];
  static int dp[2002][2002], pre[2002][2002];

  freopen("dissim.in", "r", stdin);
  freopen("dissim.out", "w", stdout);

  scanf("%s", c);
  // gets(c);
  z = strlen(c);
  alphabet.clear();
  for (int i = 0; i < z; ++i) {
    alphabet[c[i]] = i;
    mina[i] = minb[i] = 0;
  }
  scanf("%s", sa);
  // gets(sa);
  na = strlen(sa);
  for (int i = 0; i < na; ++i) {
    a[i] = alphabet[sa[i]];
  }
  scanf("%s", sb);
  // gets(sb);
  nb = strlen(sb);
  for (int i = 0; i < nb; ++i) {
    b[i] = alphabet[sb[i]];
  }
  for (int i = 0; i < z; ++i) {
    for (int j = 0; j < z; ++j) {
      scanf("%d", &dist[i][j]);
      if (dist[i][j] < dist[i][mina[i]]) {
        mina[i] = j;
      }
      if (dist[i][j] < dist[minb[j]][j]) {
        minb[j] = i;
      }
    }
  }

  dp[0][0] = 0;
  pre[0][0] = -1;
  for (int i = 0; i < na; ++i) {
    dp[i + 1][0] = dp[i][0] + dist[a[i]][mina[a[i]]];
    pre[i + 1][0] = 0;
  }
  for (int j = 0; j < nb; ++j) {
    dp[0][j + 1] = dp[0][j] + dist[minb[b[j]]][b[j]];
    pre[0][j + 1] = 1;
  }
  for (int i = 0; i < na; ++i) {
    for (int j = 0; j < nb; ++j) {
      if (dp[i][j + 1] + dist[a[i]][mina[a[i]]] < dp[i + 1][j] + dist[minb[b[j]]][b[j]]) {
        dp[i + 1][j + 1] = dp[i][j + 1] + dist[a[i]][mina[a[i]]];
        pre[i + 1][j + 1] = 0;
      } else {
        dp[i + 1][j + 1] = dp[i + 1][j] + dist[minb[b[j]]][b[j]];
        pre[i + 1][j + 1] = 1;
      }
      if (dp[i][j] + dist[a[i]][b[j]] < dp[i + 1][j + 1]) {
        dp[i + 1][j + 1] = dp[i][j] + dist[a[i]][b[j]];
        pre[i + 1][j + 1] = 2;
      }
    }
  }
  printf("%d\n", dp[na][nb]);
  z = 0;
  while (pre[na][nb] != -1) {
    switch (pre[na][nb]) {
    case 0:
      --na;
      sa[z] = c[a[na]];
      sb[z] = c[mina[a[na]]];
      break;
    case 1:
      --nb;
      sa[z] = c[minb[b[nb]]];
      sb[z] = c[b[nb]];
      break;
    case 2:
      --na;
      --nb;
      sa[z] = c[a[na]];
      sb[z] = c[b[nb]];
      break;
    }
    ++z;
  }
  reverse(sa, sa + z);
  reverse(sb, sb + z);
  sa[z] = sb[z] = '\0';
  puts(sa);
  puts(sb);

  return 0;
}
