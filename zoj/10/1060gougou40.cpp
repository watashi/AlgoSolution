#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 32;
const int MAXM = 10086;

bool e[MAXN][MAXN];

int gao(int n, bool e[MAXN][MAXN], int ans[MAXN]) {
    int ret = 1, begin = 0, end = 0;
    static int c[MAXN];

    for (int i = 0; i < n; ++i) {
        if ((c[i] = count(e[i], e[i] + n, true)) == 0) {
            ans[end++] = i;
        }
    }
    while (begin < end) {
        if (end - begin > 1) {
            ret = 2;
        }
        for (int i = 0; i < n; ++i) {
            if (e[i][ans[begin]]) {
                if (--c[i] == 0) {
                    ans[end++] = i;
                }
            }
        }
        ++begin;
    }
    if (end < n) {
        ret = 0;
    }

    return ret;
}

int main() {
    int n, m, t, r, ans[MAXN];
    char a, b;

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        t = 2;
        for (int i = 0; i < n; ++i) {
            fill(e[i], e[i] + n, false);
        }
        for (int i = 0; i < m; ++i) {
            scanf(" %c<%c", &a, &b);
            if (t == 2 && !e[b - 'A'][a - 'A']) {
                e[b - 'A'][a - 'A'] = true;
                t = gao(n, e, ans);
                r = i;
            }
        }
        if (t == 2) {
            puts("Sorted sequence cannot be determined.");
        } else if (t == 0) {
            printf("Inconsistency found after %d relations.\n", r + 1);
        } else {
            printf("Sorted sequence determined after %d relations: ", r + 1);
            for (int i = 0; i < n; ++i) {
                putchar('A' + ans[i]);
            }
            puts(".");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//245   2010-06-24 14:38:14     Accepted    1005    C++     10  180     anotherpeg  Source

// 2012-09-30 23:37:36 | Accepted | 1060 | C++ | 0 | 180 | watashi | Source
