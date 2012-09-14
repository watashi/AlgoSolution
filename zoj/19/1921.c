#include <stdio.h>
char mp[2][102][102] = {0};
int main()
{
    int re;
    int r, c, n;
    int i, j, k, t;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d%d ", &r, &c, &n);
        j = c + 1;
        for (i = 1; i <= r; i++) {
            gets(mp[0][i] + 1);
            mp[1][i][j] = 0;
        }
        for (j = 1; j <= c; j++)
            mp[0][i][j] = mp[1][i][j] = 0;
        t = 0;
        while(n--) {
            for (i = 1; i <= r; i++)
                for (j = 1; j <= c; j++) {
                    if(mp[t][i][j] == 'R') {
                        if(mp[t][i + 1][j] == 'P' || mp[t][i - 1][j] == 'P' || mp[t][i][j + 1] == 'P' || mp[t][i][j - 1] == 'P')
                            mp[1 - t][i][j] = 'P';
                        else
                            mp[1 - t][i][j] = 'R';
                    } else if(mp[t][i][j] == 'S') {
                        if(mp[t][i + 1][j] == 'R' || mp[t][i - 1][j] == 'R' || mp[t][i][j + 1] == 'R' || mp[t][i][j - 1] == 'R')
                            mp[1 - t][i][j] = 'R';
                        else
                            mp[1 - t][i][j] = 'S';
                    } else if(mp[t][i][j] == 'P') {
                        if(mp[t][i + 1][j] == 'S' || mp[t][i - 1][j] == 'S' || mp[t][i][j + 1] == 'S' || mp[t][i][j - 1] == 'S')
                            mp[1 - t][i][j] = 'S';
                        else
                            mp[1 - t][i][j] = 'P';
                    }
                }
            t = 1 - t;
        }
        for (i = 1; i <= r; i++)
            puts(mp[t][i] + 1);
        if(re)
            putchar('\n');
    }

    return 0;   /* NZEC */
}

/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //2721035    2008-01-07 13:12:00     Accepted    1921    C   00:00.40    420K    ¤ï¤¿¤· */

// 2012-09-07 03:07:00 | Accepted | 1921 | C | 220 | 180 | watashi | Source
