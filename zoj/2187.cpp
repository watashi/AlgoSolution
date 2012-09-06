#include <cstdio>
#include <cstring>

char buf[80];
int pic[11][11];

int main(void)
{
    int r, c;

    while(scanf("%s", buf) != EOF && !strcmp("START", buf)) {
        scanf("%d%d", &r, &c);
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf("%1d", &pic[i][j]);
        scanf("%*s");
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++)
                printf("%d", pic[i][j] + pic[i][j + 1] + pic[i + 1][j] + pic[i + 1][j + 1] >> 2);
            printf("\n");
        }
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2843332   2008-04-14 14:24:16     Accepted    2187    C++     00:00.00    392K    Re:ReJudge

// 2012-09-07 01:15:19 | Accepted | 2187 | C++ | 0 | 180 | watashi | Source
