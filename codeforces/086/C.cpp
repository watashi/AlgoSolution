#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;

struct AhoCorasick {
	static const int UNDEF = 0;
	static const int MAXN = 128;
	static const int CHARSET = 4;

	int end;
	int tag[MAXN];
	int fail[MAXN];
	int trie[MAXN][CHARSET];

	void init() {
		tag[0] = UNDEF;
		fill(trie[0], trie[0] + CHARSET, -1);
		end = 1;
	}

	void add(int m, const int* s, int t) {
		int p = 0;
		for (int i = 0; i < m; ++i) {
			if (trie[p][*s] == -1) {
				tag[end] = UNDEF;
				fill(trie[end], trie[end] + CHARSET, -1);
				trie[p][*s] = end++;
			}
			p = trie[p][*s];
			++s;
		}
		tag[p] = t;
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
		//	tag[p] |= tag[fail[p]];	//
			tag[p] = max(tag[p], tag[fail[p]]);
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

const int TTL = 12;
const int MAXN = 1024;
const long long MOD = 1000000009LL;

long long dp[MAXN][AhoCorasick::MAXN][TTL];

int main() {
	int n, m, l;
	int a[80];
	char buf[80];
	long long ans;
	const char pat[] = "ATCG";
	
	scanf("%d%d", &n, &m);
	ac.init();
	for (int i = 0; i < m; ++i) {
		scanf("%s", buf);
		l = strlen(buf);
		for (int i = 0; i < l; ++i) {
			a[i] = strchr(pat, buf[i]) - pat;
		}
		ac.add(l, a, l);
	}
	ac.build();

	dp[0][0][0] = 1LL;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < ac.end; ++j) {
			for (int k = 0; k < TTL; ++k) {
				if (dp[i][j][k] == 0) {
					continue;
				}
		//		printf("[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
				for (int t = 0; t < 4; ++t) {
					int jj = ac.trie[j][t];
		//			printf("=> %d (%d)\n", jj, ac.tag[jj]);
					if (ac.tag[jj] > k) {
						dp[i + 1][jj][0] += dp[i][j][k];
						dp[i + 1][jj][0] %= MOD;
					} else if (k + 1 < TTL) {
						dp[i + 1][jj][k + 1] += dp[i][j][k];
						dp[i + 1][jj][k + 1] %= MOD;
					}
				}
			}
		}
	}

	ans = 0;
	for (int j = 0; j < ac.end; ++j) {
		ans += dp[n][j][0];
	}
//	printf("%lld\n", ans % MOD);
	printf("%d\n", (int)(ans % MOD));

	return 0;
}

