// it's a NA prob

#include <cmath>
#include <cstdio>
#include <cstring>

char buf[40];
double f[108];

int main(void)
{
    int n, e;
    char* p;
    double x, y;

    while(scanf("%d%lf", &n, &x) != EOF) {
        f[102] = 0;
        f[101] = 1;
        for (int i = 100; i > 0; i--)
            f[i - 1] = (2 * i + 1) * f[i] / x - f[i + 1];
        y = f[n] * sin(x) / x / f[0];
        sprintf(buf, "%.3le", y);
        p = strchr(buf, 'e');
        *p = '\0';
        sscanf(p + 1, "%d", &e);
        printf("%s*10^%d\n", buf, e);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2916971   2008-05-15 21:12:54     Accepted    2957    C++     00:00.00    388K    Re:ReJudge

// 2012-09-07 01:50:12 | Accepted | 2957 | C++ | 0 | 180 | watashi | Source
