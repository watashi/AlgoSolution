// 1985 Largest Rectangle in a Histogram

#include <cstdio>

int a[100001], l[100001], r[100001];
long long s[100001];

int main(void)
{
    int n;
    int ind;
    long long tmp, ans;

    while (scanf("%d", &n) != EOF) {
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
        }
        l[1] = 0;
        for (int i = 2; i <= n; i++) {
            ind = i - 1;
            while (ind >= 1 && a[ind] >= a[i])
                ind = l[ind];
            l[i] = ind;
        }
        r[n] = n + 1;
        for (int i = n - 1; i >= 1; i--) {
            ind = i + 1;
            while (ind <= n && a[ind] >= a[i])
                ind = r[ind];
            r[i] = ind;
        }
        ans = -1;
        for (int i = 1; i <= n; i++) {
            tmp = a[i] * (s[r[i] - 1] - s[l[i]]);
            if (tmp > ans) {
                ind = i;
                ans = tmp;
            }
        }
        printf("%lld\n%d %d\n", ans, l[ind] + 1, r[ind] - 1);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2950567   2008-06-16 00:33:11     Accepted    2642    C++     00:01.36    2348K   Re:ReJudge

// 2012-09-07 01:33:01 | Accepted | 2642 | C++ | 490 | 2132 | watashi | Source
