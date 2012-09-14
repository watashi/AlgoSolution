#include <cstdio>
int c[4], s[4][11];
int main(void)
{
    int re;
    bool flag;
    int n, m, f, t, x;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= 3; i++) {
            c[i] = 0;
            s[i][0] = n;
        }
        c[1] = n;
        for (int i = 1; i <= n; i++)
            s[1][i] = n - i;
        flag = false;
        for (int p = 1; p <= m; p++) {
            scanf("%d%d", &f, &t);
            if(flag)
                continue;
            x = s[f][c[f]--];
            if(x == n || x > s[t][c[t]]) {
                printf("%d\n", -p);
                flag = true;
                continue;
            }
            s[t][++c[t]] = x;
            if(c[3] == n) {
                printf("%d\n", p);
                flag = true;
                continue;
            }
        }
        if(!flag)
            printf("0\n");
    }
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2814718 2008-03-31 21:56:53 Accepted 2954 C++ 00:00.08 396K ¤ï¤¿¤·

// 2012-09-07 01:49:52 | Accepted | 2954 | C++ | 20 | 180 | watashi | Source
