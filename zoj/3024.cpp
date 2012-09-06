// 运算对乘和整除封闭, 所以只要判断到sqrt(n)就可以了
// if [n % x == 0] * [n in SET] * [x in SET] then [n / x in SET];

// Fire 有一个复杂而强大的搞法，很快 orz

#include <cmath>
#include <cstdio>
#include <cstdlib>

bool p[300003];     // np = 35813

void gen_p()
{
    int n, m;

    n = 300000;
    for (int i = 0; i <= n; i++) {
        p[i] = true;
    }
    m = (int)sqrt((double)n);
    for (int i = 6, di = 5; i <= n; i += (di = 7 - di)) {
        if (p[i]) {
            if (i <= m) {
                for (int j = i * 6, dj = 5; j <= n; j += i * (dj = 7 - dj)) {
                    p[j] = false;
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    int n, m;
    static int na, a[1024];

    gen_p();
    while (scanf("%d", &n) != EOF && n > 1) {
        printf("%d:", n);
        if (p[n]) {
            printf(" %d\n", n);
            continue;
        }
        m = (int)sqrt((double)n);
        na = 0;
        for (int i = 6, t = 5; i <= m; i += (t = 7 - t)) {
            if (n % i == 0) {
                if (p[i]) {
                    printf(" %d", i);
                }
                if (n / i != m && p[n / i]) {
                    a[na++] = n / i;
                }
            }
        }
        while (na > 0) {
            printf(" %d", a[--na]);
        }
        putchar('\n');
    }

    return (EXIT_SUCCESS);
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3041316   2008-08-18 23:10:43     Accepted    3024    C++     00:00.03    692K    Re:ReJudge

/*
Rank    Submit time     Run time    Run memory      Language    User
1   2008-08-17 13:59:26     00:00.02    19724K  C++     听雨轩士
2   2008-08-18 23:10:43     00:00.03    692K    C++     Re:ReJudge
3   2008-08-18 12:48:59     00:00.03    844K    C++     Fire
4   2008-08-18 10:25:06     00:00.03    1292K   C++     ACRabbit
5   2008-08-17 13:08:21     00:00.04    828K    C++     hhb
6   2008-08-18 20:49:57     00:00.04    2212K   C++     huicpc035
7   2008-08-17 13:29:31     00:00.05    1120K   C++     fzbzchenxi
8   2008-08-18 20:29:28     00:00.05    1140K   C++     Rainco_test
9   2008-08-17 13:30:07     00:00.06    1120K   C++     chenxizju
10  2008-08-17 15:31:09     00:00.07    1240K   C++     Zerone
11  2008-08-18 17:04:27     00:00.07    1320K   C++     xdtbk
12  2008-08-18 14:31:45     00:00.07    1656K   C++     Rainco
13  2008-08-17 18:11:36     00:00.08    2220K   C++     一条没熟的鱼
14  2008-08-17 15:26:53     00:00.08    2412K   C++     nbut_vegetable
15  2008-08-17 13:35:53     00:00.08    2472K   C++     zzzz5758
16  2008-08-18 12:50:13     00:00.09    2392K   C++     EZdestroyer
17  2008-08-17 13:20:03     00:00.09    2996K   C++     keloy
18  2008-08-17 19:58:54     00:00.09    12852K  C++     kissdiik
19  2008-08-18 09:40:10     00:00.10    836K    C++     Skam
20  2008-08-17 13:17:47     00:00.10    2996K   C++     uestc08p14
*/

// 2012-09-07 01:56:06 | Accepted | 3024 | C++ | 10 | 476 | watashi | Source
