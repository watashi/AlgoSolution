#include <cstdio>
#include <cstdlib>
#include <cstring>

char buf[80];
int na, a[11][3];
int nb, b[22][3];

int main(void)
{
    int L, W, D, ans;

    while(scanf("%s", buf) != EOF && !strcmp("START", buf)) {
        scanf("%d%d%d", &L, &W, &D);
        na = 0;
        do {
            scanf("%d,%d,%d", &a[na][0], &a[na][1], &a[na][2]);
            if(a[na][2] > D)
                a[na][2] = D;
            ++na;
        }while(getchar() == ' ');
        nb = 0;
        do {
            scanf("%d,%d,%d", &b[nb][0], &b[nb][1], &b[nb][2]);
            ++nb;
        }while(getchar() == ' ');
        scanf("%*s");

        ans = 0;
        for (int i = 0; i < na; i++)
            for (int j = 0; j < nb; j++)
                if(abs(a[i][0] - b[j][0]) + abs(a[i][1] - b[j][1]) + abs(a[i][2] - b[j][2]) <= 1) {
                    b[j][0] = b[j][1] = b[j][2] = -1;
                    ++ans;
                }
        if(ans == 0)
            puts("None of dem fish blowed up!");
        else
            printf("AIEE, I got %d fish, me!\n", ans);
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2843103   2008-04-14 11:54:27     Accepted    2190    C++     00:00.01    388K    Re:ReJudge

// 2012-09-07 01:15:31 | Accepted | 2190 | C++ | 0 | 180 | watashi | Source
