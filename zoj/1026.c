#include <stdio.h>
#include <string.h>
#define FREOPEN() freopen("showinput.php", "r", stdin),freopen("test.out", "w", stdout)
char f[1001], g[1001], h[1001];
char p[1000001];
int fd, gd, hd, pd, d;
int getnum()
{
    char ch;

    while(1) {
        ch = getchar();
        if(ch == '0') return 0;
        else if(ch == '1') return 1;
    }
}
int main()
{
    int re;
    int i, j, k, t;

    /*FREOPEN();*/
    scanf("%d", &re);
    while(re--) {
        scanf("%d", &fd);
        fd--;
        for (i = fd; i >= 0; i--)
            f[i] = getnum();
        scanf("%d", &gd);
        gd--;
        for (i = gd; i >= 0; i--)
            g[i] = getnum();
        scanf("%d", &hd);
        hd--;
        for (i = hd; i >= 0; i--)
            h[i] = getnum();

        pd = fd + gd;
        /*memset(p, 0, (pd + 1) * sizeof(char));*//*BUG*/
        memset(p, 0, sizeof(p));/*MAX(pd + 1, hd)*/

        for (i = 0; i <= fd; i++) {
            if(f[i] == 0) continue;
            for (j = 0; j <= gd; j++) {
                if(g[j] == 0) continue;
                k = i + j;
                p[k] = !p[k];
            }
        }

        for (i = pd; i >= hd; i--) {
            if(p[i] == 0) continue;
            t = i - hd;
            for (j = hd; j >= 0; j--) {
                if(h[j] == 0) continue;
                k = t + j;
                p[k] = !p[k];
            }
        }

        pd = hd - 1;
        while(pd >= 0 && p[pd] == 0) pd--;
        printf("%d", pd + 1);
        for (i = pd; i >= 0; i--) {
            printf(" %d", p[i]);
        }
        putchar('\n');
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2720112 2008-01-05 22:17:15 Accepted 1026 C 00:00.04 1368K ¤ï¤¿¤· */

// 2012-09-07 00:33:19 | Accepted | 1026 | C | 10 | 1140 | watashi | Source
