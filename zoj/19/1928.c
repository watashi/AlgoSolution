#include <stdio.h>
int main()
{
    int p, a, b, c, ans;

    while(scanf("%d%d%d%d", &p, &a, &b, &c) != EOF && (p || a || b || c)) {
        ans = 80;
        if (a <= p) ans += p - a;
        else ans += 40 + p - a;
        ans += 40;
        if (b >= a) ans += b - a;
        else ans += 40 + b - a;
        if (c <= b) ans += b - c;
        else ans += 40 + b - c;
        printf("%d\n", 9 * ans);
    }
}
/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //2721040    2008-01-07 13:26:57     Accepted    1928    C   00:00.00    396K    ¤ï¤¿¤· */

// 2012-09-07 01:06:56 | Accepted | 1928 | C | 0 | 160 | watashi | Source
