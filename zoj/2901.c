/* // 1008   MV Maker  11.83% (22/186) */
#include <stdio.h>
#define SIZE 100
#define inf 0x0123456789abcdefLL
typedef long long Mat[SIZE][SIZE];
int size;
Mat mat, ans;
void op(Mat a, Mat b, Mat res)
{
    int i, j, k;
    Mat tmp;

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++) {
            tmp[i][j] = -inf;
            for (k = 0; k < size; k++)
                if(a[i][k] + b[k][j] > tmp[i][j])
                    tmp[i][j] = a[i][k] + b[k][j];
        }
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            res[i][j] = tmp[i][j];
}

void calc(Mat a, int m, Mat res)
{
    int i, j, t;
    Mat tmp;

    t = 1;
    while(t <= m) t <<= 1;
    t >>= 1;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            tmp[i][j] = a[i][j];
    while(t >>= 1) {
        op(tmp, tmp, tmp);
        if(m & t) op(tmp, a, tmp);
    }
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            res[i][j] = tmp[i][j];
}

int main()
{
    int re;
    int i, j, m;
    long long max;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d", &size, &m);
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                scanf("%lld", &mat[i][j]);
        m--;
        if(m == 0) printf("0\n");
        else {
            calc(mat, m, ans);
            max = -inf;
            for (i = 0; i < size; i++)
                for (j = 0; j < size; j++)
                    if(ans[i][j] > max) max = ans[i][j];
            printf("%lld\n", max);
        }
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2734846 2008-01-26 23:22:22 Accepted 2901 C 00:00.58 708K ¤ï¤¿¤· */

// 2012-09-07 01:45:57 | Accepted | 2901 | C | 340 | 316 | watashi | Source
