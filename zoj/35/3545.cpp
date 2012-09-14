#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct AhoCorasick {
    static const int UNDEF = 0;
    static const int MAXN = 1024;
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

const char atcg[] = "ATCG";

int main() {
    int n, m;
    char s[128];
    int l, w[10], a[128];
    bool dp[2][AhoCorasick::MAXN][1 << 10];

    while (scanf("%d%d", &n, &m) != EOF) {
        ac.init();
        for (int i = 0; i < n; ++i) {
            scanf("%s%d", s, &w[i]);
            l = strlen(s);
            for (int j = 0; j < l; ++j) {
                a[j] = strchr(atcg, s[j]) - atcg;
            }
            ac.add(l, a, 1 << i);
        }
        ac.build();

        int pre = 0, cur = 1;

        fill(dp[cur][0], dp[cur][ac.end], false);
        dp[cur][0][ac.tag[0]] = true;
        for (int i = 0; i < m; ++i) {
            swap(pre, cur);
            fill(dp[cur][0], dp[cur][ac.end], false);
            for (int j = 0; j < ac.end; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int jj = ac.trie[j][k];
                    for (int t = 0; t < (1 << n); ++t) {
                        dp[cur][jj][t | ac.tag[jj]] |= dp[pre][j][t];
                    }
                }
            }
        }

        int ans = -1;

        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < ac.end; ++j) {
                if (dp[cur][j][i]) {
                    int tmp = 0;
                    for (int k = 0; k < n; ++k) {
                        if (i & (1 << k)) {
                            tmp += w[k];
                        }
                    }
                    ans = max(ans, tmp);
                    break;
                }
            }
        }
        if (ans < 0) {  // =?
            puts("No Rabbit after 2012!");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}


//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2675331   2011-10-02 20:10:16     Accepted    3545    C++     1610    204     watashi     Source

// 2012-09-07 16:05:08 | Accepted | 3545 | C++ | 1600 | 204 | watashi | Source
