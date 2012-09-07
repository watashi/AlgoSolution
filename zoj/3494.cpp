#include <queue>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;

struct AhoCorasick {
    static const int UNDEF = 0;
    static const int MAXN = 2048;
    static const int CHARSET = 2;

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
            tag[p] |= tag[fail[p]]; //
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

const int MAXN = 218;
const long long MOD = 1000000009LL;

int next[AhoCorasick::MAXN][10];
long long dp[MAXN][AhoCorasick::MAXN];
char str[MAXN];
int num[MAXN];

int _next(int p, int x) {
    for (int i = 3; i >= 0; --i) {
        p = ac.trie[p][(x & (1 << i)) ? 1 : 0];
        if (ac.tag[p] != AhoCorasick::UNDEF) {
            return -1;
        }
    }
    return p;
}

long long gao(int m, const int* s, int p) {
    if (p == -1) {
        return 0LL;
    } else if (m == 0) {
        return 1LL;
    } else {
        long long ret = 0LL;
        for (int i = 0; i < *s; ++i) {
            int q = next[p][i];
            if (q != -1) {
                ret += dp[m - 1][q];
            }
        }
        ret += gao(m - 1, s + 1, next[p][*s]);
        return ret % MOD;
    }
}

long long gao(int m, const int* s) {
    long long ret = 1LL;
    if (m > 0) {
        ret += gao(m - 1, s + 1, next[0][*s]);
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < (i == m - 1 ? *s : 10); ++j) {
                int p = next[0][j];
                if (p != -1) {
                    ret += dp[i][p];
                }
            }
        }
        ret %= MOD;
    }
    return ret;
}

int main() {
    int re, n, m;
    long long ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        ac.init();
        for (int i = 0; i < n; ++i) {
            scanf("%s", str);
            m = strlen(str);
            transform(str, str + m, num, bind2nd(minus<char>(), '0'));
            ac.add(m, num, 1);
        }
        ac.build();

        for (int i = 0; i < ac.end; ++i) {
            for (int j = 0; j < 10; ++j) {
                next[i][j] = ac.tag[i] == AhoCorasick::UNDEF ? _next(i, j) : -1;
            }
        }
        for (int j = 0; j < ac.end; ++j) {
            dp[0][j] = ac.tag[j] != AhoCorasick::UNDEF ? 0 : 1;
        }
        for (int i = 1; i < MAXN; ++i) {
            for (int j = 0; j < ac.end; ++j) {
                dp[i][j] = 0;
                if (ac.tag[j] == AhoCorasick::UNDEF) {
                    for (int k = 0; k < 10; ++k) {
                        int jj = next[j][k];
                        if (jj != -1) {
                            dp[i][j] += dp[i - 1][jj];
                        }
                    }
                    dp[i][j] %= MOD;
                }
            }
        }

        scanf("%s", str);
        m = strlen(str);
        transform(str, str + m, num, bind2nd(minus<char>(), '0'));
        for (int i = m - 1; i >= 0; --i) {
            if (num[i] == 0) {
                num[i] = 9;
            } else {
                --num[i];
                break;
            }
        }
        if (num[0] == 0) {
            ans = -gao(m - 1, num + 1);
        } else {
            ans = -gao(m, num);
        }

        scanf("%s", str);
        m = strlen(str);
        transform(str, str + m, num, bind2nd(minus<char>(), '0'));
        ans += gao(m, num);

        ans = (ans % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }
    assert(scanf("%d", &re) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//473   2011-04-15 01:49:17     Accepted    H   C++     1230    3780    watashi     Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//3     2011-04-15 23:04:18     Accepted    H   C++     800     3780    watashi@ArcOfDream  Source

// 2012-09-07 16:01:53 | Accepted | 3494 | C++ | 800 | 3780 | watashi | Source
