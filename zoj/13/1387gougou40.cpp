#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cstring>

const int MAXL = 12321;
const int MAXN = 200200;

struct Trie {
    int n, tag[MAXN], child[MAXN][2];

    void clear() {
        child[0][0] = child[0][1] = -1;
        tag[0] = 0;
        n = 1;
    }

    int add(const char* str, int p = 0) {
        while (*str != '\0') {
            int q = (*str++ == '-');
            if (child[p][q] == -1) {
                child[n][0] = child[n][1] = -1;
                tag[n] = 0;
                child[p][q] = n++;
            }
            p = child[p][q];
        }
        return p;
    }
};

const char* morse[] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
};

int main() {
    int re, n, m, p;
    char code[MAXL], buf[80];
    int dp[MAXL];
    Trie trie;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%s%d", code, &m);
        n = strlen(code);
        trie.clear();
        for (int i = 0; i < m; ++i) {
            scanf("%s", buf);
            p = 0;
            for (int j = 0; buf[j] != '\0'; ++j) {
                p = trie.add(morse[buf[j] - 'A'], p);
            }
            ++trie.tag[p];
        }

        for (int i = 0; i < n; ++i) {
            code[i] = (code[i] == '-');
        }
        memset(dp, 0, (n + 1) * sizeof(int));
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            p = 0;
            for (int j = i; trie.child[p][code[j]] != -1 && j < n; ++j) {
                p = trie.child[p][code[j]];
                if (trie.tag[p] > 0) {
                    dp[j + 1] += dp[i] * trie.tag[p];
                }
            }
        }
        printf("%d\n", dp[n]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//291   2010-06-27 06:26:07     Accepted    1026    C++     330     180     anotherpeg  Source

// 2012-09-30 23:39:55 | Accepted | 1387 | C++ | 240 | 180 | watashi | Source
