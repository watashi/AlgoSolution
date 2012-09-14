#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

typedef struct{
    int id;
    int begin;
    int end;
}Cache;
Cache a[SIZE];
int x[SIZE];

int cmp(const void* pa, const void* pb)
{
    if(((Cache*)pa) -> begin == -1) return 1;
    else if(((Cache*)pb) -> begin == -1) return -1;
    else return (((Cache*)pa) -> begin < ((Cache*)pb) -> begin) ? -1 : 1;
}

int main()
{
    int i, t, m, n;

    while(scanf("%d", &n) != EOF) {
        if(n == 0){
            printf("0\n");/*T_T so xe*/
            continue;
        }
        for (i = 0; i < SIZE; i++) {
            a[i].id = i;
            a[i].begin = -1;
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &t);
            if(a[t].begin == -1) a[t].begin = i;
            a[t].end = i;
        }
        qsort(a, SIZE, sizeof(Cache), cmp);
        n = SIZE;
        while(n && a[n - 1].begin == -1) n--;
        for (m = 1; m < SIZE; m++) {
            memset(x, 0xff, m * sizeof(int));
            for (i = 0; i < n; i++) {
                t = a[i].id % m;
                if(a[i].begin <= x[t]) break;
                else x[t] = a[i].end;
            }
            if(i == n) break;
        }
        printf("%d\n", m);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2735476 2008-01-27 16:39:57 Accepted 2895 C 00:01.26 428K ¤ï¤¿¤· */

// 2012-09-07 03:14:50 | Accepted | 2895 | C | 340 | 176 | watashi | Source
