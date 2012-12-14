#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct AhoCorasick {
	static const int UNDEF = 0;
	static const int MAXN = 128;
	static const int CHARSET = 10;

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
			tag[p] |= 1 << *s;
			++s;
		}
		tag[p] |= t;
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
			tag[p] |= tag[fail[p]];	//
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

long long dp[16][AhoCorasick::MAXN];

int main() {
	int re, n, m, l;
	long long cnt[10], tmp, ans;
	set<int> s[10], t;
	char b[80];
	int a[80];
	
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		ac.init();
		for (int i = 0; i < 10; ++i) {
			a[0] = i;
			ac.add(1, a, 0);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%s", b);
			m = strlen(b);
			for (int j = 0; j < m; ++j) {
				a[j] = b[j] - '0';
			}
			reverse(a, a + m);
			ac.add(m, a, 1 << 10);
		}
		ac.build();

		fill(dp[0], dp[16], 0);
		dp[0][0] = 1;
		for (int i = 1; i < 16; ++i) {
			for (int j = 0; j < ac.end; ++j) {
				if (dp[i - 1][j] == 0) {
					continue;
				}
				for (int k = 0; k < 10; ++k) {
					int jj = ac.trie[j][k];
					if ((ac.tag[jj] >> 10) == 0) {
						dp[i][jj] += dp[i - 1][j];
					}
				}
			}
		}

		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &m);
			--m;

			l = 1;
			while (true) {
				tmp = 0;
				for (int j = 1; j < ac.end; ++j) {
					if ((ac.tag[j] & 1) == 0) {
						tmp += dp[l][j];
					}					
				}
				if (m < tmp) {
					break;
				} else {
					++l;
					m -= tmp;
				}
			}

			ans = 0;
			while (l > 0) {
				for (int j = 0; j < 10; ++j) {
					s[j].clear();
					cnt[j] = 0;
				}
				for (int j = 1; j < ac.end; ++j) {
					int k = __builtin_ctz(ac.tag[j]);
					if ((ac.tag[j] >> 10) == 0 && (
							(ans == 0 && k != 0) ||
							(ans != 0 && t.count(ac.trie[j][ans % 10]) != 0))) {
						s[k].insert(j);
						cnt[k] += dp[l][j];
					}
				}
				for (int j = 0; j < 10; ++j) {
					if (m < cnt[j]) {
						t = s[j];
						ans = ans * 10 + j;
						break;
					} else {
						m -= cnt[j];
					}
				}
				--l;
			}
			printf("%lld%c", ans, i == n - 1 ? '\n' : ' ');
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//866475 	5064 	Serial Numbers 	Accepted 	C++ 	0.124 	2011-08-26 05:30:22
/*
id => 1174306
pid => 5064
pname => Serial Numbers
status => Accepted
lang => C++
time => 0.072
date => 2012-12-14 17:52:06
*/
