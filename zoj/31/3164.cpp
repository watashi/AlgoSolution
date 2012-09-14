#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 123456789;
int k[1234], e[1234], p[1234], l[1234];
int ng, cg, g[1234];
int d, tp[1234], dp[1234];

// cg * d
void dp_group()
{
    tp[0] = 0;
    for (int i = 1; i <= d; i++) {
        tp[i] = -inf;
    }
    for (int ig = 0; ig < cg; ig++) {
        int t = g[ig];
        for (int i = ((k[t] == 0) ? d : k[t]), j = p[t], k = e[t]; i > 0 && j <= d; --i, j += p[t], k += e[t]) {    //WA    //WA
            tp[j] = max(tp[j], k);
        }
    }
}

// d ^ 2
void merge_group()
{
    for (int i = d; i >= 0; i--) {
        for (int j = d; j > i; j--) {
            dp[j] = max(dp[j], dp[i] + tp[j - i]);
        }
    }
}

// d
void dp_an_element(int e, int p)
{
    for (int i = d - p; i >= 0; i--) {
        dp[i + p] = max(dp[i + p], dp[i] + e);
    }
}

// d
void dp_inf_element(int e, int p)
{
    for (int i = p; i <= d; i++) {
        dp[i] = max(dp[i], dp[i - p] + e);
    }
}

// d * lgn
// /* * * * * * * * * * *   * * * * * * * * * * * /
void dp_n_element(int n, int e, int p)
{
    if (n == 0) {
        dp_inf_element(e, p);
    }
    else {
        for (int i = 1; i <= n; i <<= 1) {
            dp_an_element(e * i, p * i);
            n -= i;
        }
        if (n > 0) {
            dp_an_element(e * n, p * n);
        }
    }
}

void get_group()
{
    do {
        scanf("%d", &g[cg]);
        --g[cg];    //begin with 1
        l[g[cg]] = ng;
        ++cg;
    } while (getchar() != '\n');
}

int main(void)
{
    int n;

    while (scanf("%d%d", &n, &d) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &k[i], &e[i], &p[i]);
            l[i] = -1;
        }
        dp[0] = 0;
        for (int i = 1; i <= d; i++) {
            dp[i] = -inf;
        }
        scanf("%d", &ng);
        while (ng--) {
            cg = 0;
            get_group();
            dp_group();
            merge_group();
        }
        for (int i = 0; i < n; i++) {
            if (l[i] == -1) {
                dp_n_element(k[i], e[i], p[i]);
            }
        }
        if (dp[d] < 0) {
            puts("i'm sorry...");
        }
        else {
            printf("%d\n", dp[d]);
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801110   2009-03-23 21:09:50     Accepted    3164    C++     610     212     watashi@Zodiac

// 2012-09-07 02:05:06 | Accepted | 3164 | C++ | 440 | 212 | watashi | Source
