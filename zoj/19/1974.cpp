//解方程i组
//n为奇数时有唯一解，且解可在O(n)回代求得
#include <cctype>
#include <cstdio>

//double x[1234];
//double y[1234];
long long x[150];
long long y[150];

inline long long getll()
{
    bool flag = false;
    char ch;
    long long ret = 0;

    while(!isdigit(ch = getchar()))
        if(ch == '-')
            flag = true;
    do {
        ret *= 10;
        ret += ch - '0';
    }while(isdigit(ch = getchar()));

    return (flag) ? -ret : ret;
}

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            //scanf("%lld%lld", &x[i], &y[i]);
            x[i] = getll() << 1;
            y[i] = getll() << 1;
            //scanf("%lf%lf", &x[i], &y[i]);
        }
        for (int i = 1; i < n; i++) {
            if(i & 1)
                x[n] -= x[i], y[n] -= y[i];
            else
                x[n] += x[i], y[n] += y[i];
        }
        x[n] >>= 1; //x[n] /= 2.0;
        y[n] >>= 1; //y[n] /= 2.0;
        for (int i = n - 1; i >= 1; i--)
            x[i] -= x[i + 1], y[i] -= y[i + 1];
        printf("%d", n);
        for (int i = 1; i <= n; i++)
            printf(" %lld.000000 %lld.000000", x[i], y[i]);
            //printf(" %.6lf %.6lf", 2 * x[i], 2 * y[i]);
        printf("\n");
    }

    return 0;
}

//double
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2843561   2008-04-14 16:36:45     Accepted    1974    C++     00:00.02    408K    Re:ReJudge

//long long
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2843576   2008-04-14 16:44:38     Accepted    1974    C++     00:00.02    396K    Re:ReJudge


//getll()
//2843591   2008-04-14 16:56:17     Accepted    1974    C++     00:00.01    396K    Re:ReJudge

// 2012-09-07 01:09:07 | Accepted | 1974 | C++ | 0 | 180 | watashi | Source
