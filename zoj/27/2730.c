/* //构造欧拉回路 */
/* //应该用邻接表写快得多！！ */
#include <stdio.h>
int blank, n;
int mp[50][50];
void printEuler(int begin, int end)
{
    int i, j;
    int l, lt[100];

    l = 0;
    i = begin;
    do {
        for (j = 0; j < n; j++)
            if(mp[i][j]) {
                mp[i][j]--;
                mp[j][i]--;
                break;
            }
        if (j == n) return;
        else i = lt[l++] = j;
    }while(i != end);
    printEuler(begin, begin);
    for (i = 0; i < l; i++) {
        if (blank) putchar(' ');
        else blank = 1;
        printf("%d", lt[i]);
        printEuler(lt[i], lt[i]);
    }
}
int main()
{
    int i, j;

    while(scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++){
            mp[i][i] = 0;
            for (j = 0; j < i; j++)
                mp[i][j] = mp[j][i] = 1;
        }
        if(n&1) {
            printf("%d\n", n * (n - 1) / 2);
        }
        else {
            for (i = 0; i < n; i+=2)
                mp[i][i + 1] = mp[i + 1][i] = 2;
            printf("%d\n", n * n / 2);
        }
        blank = 0;
        printEuler(0, 0);
        putchar('\n');
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2711277 2007-12-23 13:31:57 Accepted 2730 C 00:00.00 420K わたし */

// 2012-09-07 03:12:24 | Accepted | 2730 | C | 0 | 168 | watashi | Source
