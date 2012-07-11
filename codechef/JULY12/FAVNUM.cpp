#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXD = 19;

struct AhoCorasick {
	static const int NONE = 0;
	static const int MAXN = 4096;
	static const int CHARSET = 10;

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

llint ten[MAXD];
llint dp[MAXD][AhoCorasick::MAXN];

void init() {
    ten[0] = 1;
    for (int i = 1; i < MAXD; ++i) {
        ten[i] = ten[i - 1] * 10;
    }
}

llint gao(llint n) {
    int m = 0;
    while (n / ten[m] >= 10) {
        ++m;
    }

    int p = 0;
    llint ret = 0;
    while (m >= 0) {
        if (ac.tag[p] != 0) {
            break;
        }
        int d = n / ten[m] % 10;
        for (int i = 0; i < d; ++i) {
            ret += dp[m][ac.trie[p][i]];
        }
        p = ac.trie[p][d];
        --m;
    }
    return n - ret;
}

int main() {
    long long l, r, m, k;
    int n, t, a[80];
    char buf[80];

    init();
    scanf("%lld%lld%lld%d", &l, &r, &k, &n);
    ac.init();
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        t = (int)strlen(buf);
        for (int j = 0; j < t; ++j) {
            a[j] = buf[j] - '0';
        }
        ac.tag[ac.add(t, a)] = 1;
    }
    ac.build();

    for (int i = 0; i < ac.end; ++i) {
        dp[0][i] = (ac.tag[i] == 0 ? 1 : 0);
    }
    for (int i = 1; i < MAXD; ++i) {
        for (int j = 0; j < ac.end; ++j) {
            dp[i][j] = 0;
            if (ac.tag[j] == 0) {
                for (int k = 0; k < AhoCorasick::CHARSET; ++k) {
                    dp[i][j] += dp[i - 1][ac.trie[j][k]];
                }
            }
        }
    }

    k += gao(l);
    if (gao(r + 1) < k) {
        puts("no such number");
    } else {
        r = r + 1;
        while (l < r) {
            m = (l + r) / 2;
            if (gao(m) < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        printf("%lld\n", r - 1);
    }

    return 0;
}

//Correct Answer
//Execution Time: 0.13

