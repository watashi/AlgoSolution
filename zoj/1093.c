/* //可以对x、y要求条件x<=y，缩小一半的状态数！ */
/* //其实规模很弱 */
#include <stdio.h>
#include <stdlib.h>
struct Block{
    int x;
    int y;
    int z;
};

int cmp(const void *pa, const void *pb)
{
    struct Block *a = (struct Block *)pa, *b = (struct Block *)pb;

    if(a->x == b->x){
        if(a->y == b->y) return 0;
        else return (a->y < b->y) ? -1 : 1;
    }
    return (a->x < b->x) ? -1 : 1;
}

struct Block a[200];
int dp[200];

int main()
{
    int ri = 0;
    int i, j, n, ans;

    while(scanf("%d", &n) != EOF && n) {
        i = 0;
        while(n--) {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
            j = i;
            ++j; a[j].x = a[i].x; a[j].y = a[i].z; a[j].z = a[i].y;
            ++j; a[j].x = a[i].y; a[j].y = a[i].x; a[j].z = a[i].z;
            ++j; a[j].x = a[i].y; a[j].y = a[i].z; a[j].z = a[i].x;
            ++j; a[j].x = a[i].z; a[j].y = a[i].x; a[j].z = a[i].y;
            ++j; a[j].x = a[i].z; a[j].y = a[i].y; a[j].z = a[i].x;
            i = j + 1;
        }
        n = i;
        qsort(a, n, sizeof(struct Block), cmp);
        ans = 0;
        for (i = 0; i < n; i++) {
            dp[i] = 0;
            for (j = 0; j < i; j++)
                if(a[j].x < a[i].x && a[j].y < a[i].y && dp[j] > dp[i]) dp[i] = dp[j];
            dp[i] += a[i].z;
            if(dp[i] > ans) ans = dp[i];
        }
        printf("Case %d: maximum height = %d\n", ++ri, ans);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2712249 2007-12-24 20:24:56 Accepted 1093 C 00:00.01 400K わたし */

// 2012-09-07 00:36:27 | Accepted | 1093 | C | 0 | 164 | watashi | Source
