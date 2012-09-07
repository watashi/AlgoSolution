//dp不行、状态太多
//于是回归递归
//好题目啊
#include <cstdio> // auto fix CE
#include <stdio.h>
int islegal(int x, int t)
{
    int i;

    if (x == 1) return 1;
    for (i = t; i <= 100; i++)
        if (x % i == 0 && islegal(x / i, i + 1)) return 1;
    return 0;
}

int doit(int x, int y, int t)
{
    int i;

    if (x == 1 && y == 1) return 1;
    for (i = t; i <= 100; i++) {
        if (x % i == 0 && doit(x / i, y, i + 1)) return 1;
        if (y % i == 0 && doit(x, y / i, i + 1)) return 1;
    }
    return 0;
}

int main()
{
    int x, y, z;

    while(scanf("%d%d", &x, &y) != EOF) {
        if (x < y) {
            z = x;
            x = y;
            y = z;
        }
        if (islegal(y, 2)) z = doit(x, y, 2) ? x : y;
        else z = x;
        printf("%d\n", z);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2712225 2007-12-24 19:20:52 Accepted 1003 C 00:00.03 396K わたし

//：改进反而慢了，因为很多case没有break
/*
#include <cstdio> // auto fix CE
#include <stdio.h>
int flag;

int doit(int x, int y, int t)
{
    int i;

    if (y == 1) flag = 1;
    if (x == 1 && y == 1) return 1;
    for (i = t; i <= 100; i++) {
        if (x % i == 0 && doit(x / i, y, i + 1)) return 1;
        if (y % i == 0 && doit(x, y / i, i + 1)) return 1;
    }
    return 0;
}

int main()
{
    int x, y, z;

    while(scanf("%d%d", &x, &y) != EOF) {
        if (x < y) {
            z = x;
            x = y;
            y = z;
        }
        flag = 0;
        if (doit(x, y, 2) || !flag) printf("%d\n", x);
        else printf("%d\n", y);
    }
}
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2712228 2007-12-24 19:26:17 Accepted 1003 C 00:00.06 392K わたし
2712227 2007-12-24 19:25:49 Accepted 1003 C 00:00.06 388K わたし
*/

// 2012-09-07 14:08:16 | Accepted | 1003 | C++ | 10 | 180 | watashi | Source
