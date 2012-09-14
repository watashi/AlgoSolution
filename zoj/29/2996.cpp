#include <cstdio>

int calc(int x, int y)
{
    int ret = 0;

    while(x != 0) {
        ret += x / y;
        x /= y;
    }

    return ret;
}

int main(void)
{
    int n, k, c;

    while (scanf("%d%d", &n, &k) != EOF) {
        c = calc(n, 2) - calc(k, 2) - calc(n - k, 2);
        printf("%d\n", c == 0 ? 1 : 0);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//530   2008-06-21 14:24:43     Accepted    1001    C++     00:00:00    392K    Re:ReJudge

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2954368   2008-06-22 03:13:40     Accepted    2996    C++     00:00.00    388K    Re:ReJudge

// 2012-09-07 01:53:28 | Accepted | 2996 | C++ | 0 | 180 | watashi | Source
