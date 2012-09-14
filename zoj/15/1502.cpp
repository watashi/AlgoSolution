#include <cstdio>
#include <cstdlib>

#define GEN(BEGINI, ENDI, NEXTI, BEGINJ, ENDJ, NEXTJ, MP) { \
    int k = 0;  \
    for (int i = BEGINI; i != ENDI; NEXTI)  \
        for (int j = BEGINJ; j != ENDJ; NEXTJ)  \
            ++k, MP[k][0] = i, MP[k][1] = j;    \
    }

int n, nn, p[10001][2], h[10001][2];

void gen(int n, int type)
{
    switch(type) {
        case 0:
            GEN(0, n, ++i, 0, n, ++j, h);
            break;
        case 1:
            GEN(0, n, ++i, n - 1, -1, --j, h);
            break;
        case 2:
            GEN(n - 1, -1, --i, 0, n, ++j, h);
            break;
        case 3:
            GEN(n - 1, -1, --i, n - 1, -1, --j, h);
            break;
    }
}

int m, t[10001][2];

int test(int n, int type)
{
    int ret1 = 0, ret2 = 0;

    gen(n, type);
    for (int i = 0; i < m; i++) {
        ret1 += abs(p[t[i][0]][0] - h[t[i][1]][0]) + abs(p[t[i][0]][1] - h[t[i][1]][1]);
        ret2 += abs(p[t[i][0]][0] - h[t[i][1]][1]) + abs(p[t[i][0]][1] - h[t[i][1]][0]);
    }

    return ret1 < ret2 ? ret1 : ret2;
}

int main(void)
{
    int ri = 0, ans;

    while(scanf("%d", &n) != EOF && n > 0) {
        nn = n * n;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%d%d", &t[i][0], &t[i][1]);
        GEN(0, n, ++i, 0, n, ++j, p);
        ans = 123456789;
        for (int type = 0; type < 4; type++)
            /* ans <?= test(n, type); */ /* auto fix <?= */
            ans = ans < test(n, type) ? ans : test(n, type);
        if(ri > 0)
            putchar('\n');
        printf("Scenario %d: smallest average = %.4lf\n", ++ri, 1.0 * ans / m + 1.0);
    }

    return 0;
}
//2843414   2008-04-14 15:22:28     Accepted    1502    C++     00:00.03    632K    Re:ReJudge

// 2012-09-07 13:54:16 | Accepted | 1502 | C++ | 10 | 416 | watashi | Source
