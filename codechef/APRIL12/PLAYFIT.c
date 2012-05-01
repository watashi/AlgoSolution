#include <stdio.h>

int main(void) {
    int ri, re;
    int i, n;
    int x, y;
    int ans;

    scanf("%d", &re);
    for (ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &x);
        ans = 0;
        for (i = 1; i < n; ++i) {
            scanf("%d", &y);
            if (ans < y - x) {
                ans = y - x;
            }
            if (x > y) {
                x = y;
            }
        }
        if (ans > 0) {
            printf("%d\n", ans);
        } else {
            puts("UNFIT");
        }
    }

    return 0;
}

