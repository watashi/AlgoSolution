//algo:greedy

#include <cstdio>

int re, n, ans;
char pre, tmp;

int main(void)
{
    scanf("%d", &re);
    for (int ri = 0; ri < re; ri++) {
        if(ri > 0) putchar('\n');
        scanf("%d", &n);
        ans = 0;
        scanf(" %c", &pre);
        for (int i = 1; i < n; i++) {
            scanf(" %c", &tmp);
            if(tmp != pre) {
                pre = tmp;
                ++ans;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2770413 2008-03-04 21:57:28 Accepted 1171 C++ 00:00.28 392K ¤ï¤¿¤·

// 2012-09-07 00:40:00 | Accepted | 1171 | C++ | 80 | 180 | watashi | Source
