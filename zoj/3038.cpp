#include <cstdio>
#include <cstring>

int mask[21] = {
    6, 29, 51, 210, 430, 788, 3208, 6488, 12976, 24864, 100416, 201920, 403840,
    807680, 1581568, 66560, 166912, 333824, 667648, 1335296, 540672
};

int bin[22], all[22];
int b[1 << 21], q[1 << 21];

int bfs(int s, int m)
{
    int p = 0, t = 1, ss;
    int cnt, ret = 0;

    memset(b, 0, bin[m] * sizeof(int));
    q[0] = s;
    b[0] = 1;
    while (p < t) {
        s = q[p];
        cnt = 0;
        for (int i = 0; i < m; i++) {
            if (s & bin[i]) {
                ++cnt;
                ss = ((s ^ mask[i]) & all[m]);
                if (!b[ss]) {
                    b[ss] = 1;
                    q[t++] = ss;
                }
            }
        }
        // ...
        if (b[all[m]]) {
            return m;
        }
        // ...
        if (cnt > ret) {
            ret = cnt;
        }
        ++p;
    }

    return ret;
}

int main(void)
{
    char ch;
    int n, m, s;

    for (int i = 0; i <= 21; i++) {
        bin[i] = (1 << i);
        all[i] = bin[i] - 1;
        mask[i] |= bin[i];
    }
    while (scanf("%d", &n) != EOF) {
        m = n * (n + 1) / 2;
        s = 0;
        for (int i = 0; i < m; i++) {
            scanf(" %c", &ch);
            if (ch == '.') {
                s |= bin[i];
            }
        }
        printf("%d\n", bfs(s, m));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1645669   2008-09-15 22:37:44     Accepted    3038    C++     2910    16644   watashi

// 2012-09-07 01:57:26 | Accepted | 3038 | C++ | 2750 | 16564 | watashi | Source
