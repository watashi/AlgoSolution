#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cstring>

const int MAXN = 128;

char buf[MAXN];
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

int gao(int begin, int end) {
    if (dp[begin][end] == -1) {
        switch (end - begin) {
            case 0: return dp[begin][end] = 0;
            case 1: return dp[begin][end] = 1;
            default: dp[begin][end] = MAXN;
        }
        if ((buf[begin] == '(' && buf[end - 1] == ')') || (buf[begin] == '[' && buf[end - 1] == ']')) {
            dp[begin][end] = gao(begin + 1, end - 1);
            pre[begin][end] = -1;
        }
        // not `else { ... }` => (WA)
        for (int i = begin + 1; i < end; ++i) {
            if (dp[begin][end] > gao(begin, i) + gao(i, end)) {
                dp[begin][end] = gao(begin, i) + gao(i, end);
                pre[begin][end] = i;
            }
        }
    }
    return dp[begin][end];
}

void print(int begin, int end) {
    if (end - begin == 0) {
    } else if (end - begin == 1) {
        switch (buf[begin]) {
        case '(': case ')': printf("()"); break;
        case '[': case ']': printf("[]"); break;
        }
    } else if (pre[begin][end] == -1) {
        putchar(buf[begin]);
        print(begin + 1, end - 1);
        putchar(buf[end - 1]);
    } else {
        print(begin, pre[begin][end]);
        print(pre[begin][end], end);
    }
}

int main() {
    int re, n;

    scanf("%d", &re);
    gets(buf);
    for (int ri = 1; ri <= re; ++ri) {
        if (ri > 1) {
            puts("");
        }
        gets(buf);
        gets(buf);
        n = strlen(buf);
        memset(dp, 0xff, sizeof(dp));
        gao(0, n);
        print(0, n);
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//271   2010-06-25 22:41:19     Accepted    1036    C++     40  308     anotherpeg  Source

// 2012-09-30 23:41:00 | Accepted | 1463 | C++ | 10 | 308 | watashi | Source
