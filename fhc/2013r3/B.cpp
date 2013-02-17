#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

struct AhoCorasick {
	static const int NONE = 0;
	static const int MAXN = 12800;
	static const int CHARSET = 26;

	int end;
	int tag[MAXN];
	int fail[MAXN];
	int trie[MAXN][CHARSET];

	void init() {
		tag[0] = NONE;
		fill(trie[0], trie[0] + CHARSET, -1);
		end = 1;
	}

	int add(int m, const int* s) {
		int p = 0;
		for (int i = 0; i < m; ++i) {
			if (trie[p][*s] == -1) {
				tag[end] = NONE;
				fill(trie[end], trie[end] + CHARSET, -1);
				trie[p][*s] = end++;
			}
			p = trie[p][*s];
			++s;
		}
		return p;
	}

	void build() {
		queue<int> bfs;
		fail[0] = 0;
		for (int i = 0; i < CHARSET; ++i) {
			if (trie[0][i] != -1) {
				fail[trie[0][i]] = 0;
				bfs.push(trie[0][i]);
			} else {
				trie[0][i] = 0;
			}
		}
		while (!bfs.empty()) {
			int p = bfs.front();
			tag[p] |= tag[fail[p]];
			bfs.pop();
			for (int i = 0; i < CHARSET; ++i) {
				if (trie[p][i] != -1) {
					fail[trie[p][i]] = trie[fail[p]][i];
					bfs.push(trie[p][i]);
				} else {
					trie[p][i] = trie[fail[p]][i];
				}
			}
		}
	}
} ac;

const int MAXL = 128;
const long long INF = 1234567890987654321LL;

long long dp[MAXL][AhoCorasick::MAXN][2];

void add(long long& lhs, const long long& rhs) {
  lhs += rhs;
  if (lhs > INF) {
    lhs = INF;
  }
}

void gen(int n, int p, int q, long long k) {
  if (n == 0) {
    puts("");
  } else {
    for (int i = 0; i < AhoCorasick::CHARSET; ++i) {
      int pp = ac.trie[p][i];
      int qq = q | ac.tag[pp];
      if (k <= dp[n - 1][pp][qq]) {
        putchar('a' + i);
        gen(n - 1, pp, qq, k);
        break;
      } else {
        k -= dp[n - 1][pp][qq];
      }
    }
  }
}

int main() {
  int re, n, m;
  long long k;
  char buf[MAXL];
  int a[MAXL];

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%lld%d", &n, &k, &m);
    ac.init();
    for (int i = 0; i < m; ++i) {
      scanf("%s", buf);
      int len = strlen(buf);
      for (int j = 0; j < len; ++j) {
        a[j] = buf[j] - 'a';
      }
      ac.tag[ac.add(len, a)] = 1;
    }
    ac.build();

    m = ac.end;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i) {
      dp[0][i][0] = 0;
      dp[0][i][1] = 1;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 2; ++k) {
          for (int l = 0; l < AhoCorasick::CHARSET; ++l) {
            int jj = ac.trie[j][l];
            int kk = k | ac.tag[jj];
            add(dp[i + 1][j][k], dp[i][jj][kk]);
          }
        }
      }
    }
/*
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 2; ++k) {
          printf("[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
        }
      }
    }
*/
    printf("Case #%d: ", ri);
    // printf("%lld\n", dp[n][0][0]);
    if (k > dp[n][0][0]) {
      puts("unnamed baby :(");
    } else {
      gen(n, 0, 0, k);
    }
    fflush(stdout);
  }

  return 0;
}

