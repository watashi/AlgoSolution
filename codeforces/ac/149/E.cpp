#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

char r[MAXN], s[MAXN], t[MAXN];
int fr[MAXN], fs[MAXN], gr[MAXN], gs[MAXN];

int maxint(int lhs, int rhs) {
    return max(lhs, rhs);
}

void initFail(int len, const char pat[], int fail[]) {
    fail[0] = -1;
    for (int i = 1; i < len; ++i) {
        int k = fail[i - 1];
        while (k >= 0 && pat[k + 1] != pat[i]) {
            k = fail[k];
        }
        fail[i] = (pat[k + 1] == pat[i]) ? k + 1 : -1;
    }
}

void kmpFind(int len, const char pat[], const int fail[], const char str[], int r[]) {
    const char *p = str;
    int k = 0;
    while (*p != '\0') {
        if (*p == pat[k]) {
            r[p - str] = k + 1;
            ++p;
            ++k;
            if (k == len) {
                k = fail[k - 1] + 1;
            }
        } else if (k > 0) {
            k = fail[k - 1] + 1;
        } else {
            r[p - str] = 0;
            ++p;
        }
    }
}

int main() {
    int n, m, q, ans;

    scanf("%s", s);
    n = strlen(s);
    copy(s, s + n + 1, r);
    reverse(r, r + n);

    scanf("%d", &q);
    ans = 0;
    for (int i = 0; i < q; ++i) {
        scanf("%s", t);
        m = strlen(t);
        if (m == 1) {
            continue;
        }
        initFail(m, t, fs);
        kmpFind(m, t, fs, s, gs);
        reverse(t, t + m);
        initFail(m, t, fr);
        kmpFind(m, t, fr, r, gr);

        // for (int j = 0; j < n; ++j) {
        //     printf("%d %d\n", gs[j], gr[j]);
        // }
        partial_sum(gs, gs + n, gs, maxint);
        partial_sum(gr, gr + n, gr, maxint);

        for (int i = 1; i < n; ++i) {
            int x = gs[i - 1];
            int y = gr[n - i - 1];
            if (x > 0 && y > 0 && x + y >= m) {
                // printf("[%d] %d [%d] %d\n", i - 1, x, n - i - 1, y);
                ++ans;
                break;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1169174 	Feb 10, 2012 10:32:55 PM 	watashi 	E - Martian Strings 	GNU C++ 	Accepted 	220 ms 	3200 KB
