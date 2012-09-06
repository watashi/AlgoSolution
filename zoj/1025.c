#include <stdio.h>
#include <stdlib.h>
#define MAXN 10001
typedef struct{
    int l;
    int w;
}Stick;
Stick a[MAXN];

int cmp(const void *pa, const void *pb)
{
    Stick *a = (Stick *)pa, *b = (Stick *)pb;

    if(a -> l == b -> l) return (a -> w < b -> w) ? -1 : 1;
    else return (a -> l < b -> l) ? -1 : 1;
}

int w[MAXN];
int main()
{
    int re;
    int l, r, mid, len, i, n;

    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d%d", &a[i].l, &a[i].w);
        qsort(a, n, sizeof(Stick), cmp);
        len = 0;
        w[len] = a[0].w;
        for (i = 1; i < n; i++) {
            if(a[i].w < w[len]) w[++len] = a[i].w;
            else if(a[i].w >= w[0]) w[0] = a[i].w;/*可去掉，但会变慢*/
            else {
                l = 0;
                r = len;
                while(l < r) {
                    mid = (l + r) >> 1;
                    if(a[i].w < w[mid]) l = mid + 1;
                    else r =mid;
                }
                w[l] = a[i].w;
            }
        }
        printf("%d\n", len + 1);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2720200 2008-01-05 23:18:37 Accepted 1025 C 00:00.02 556K わたし */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2720201 2008-01-05 23:19:06 Accepted 1025 C 00:00.03 556K わたし */

// 2012-09-07 00:33:13 | Accepted | 1025 | C | 0 | 280 | watashi | Source
