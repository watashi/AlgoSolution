/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!*He does not have to use all the wires.*!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
#include <stdio.h>
#define eps 1e-8
int main()
{
    int i, j, k, n;
    double r[20], sum;

    while(scanf("%d", &n) != EOF && n) {
        for (i = 0; i < n; i++)
            scanf("%lf", &r[i]);
        for (i = 0; i < n; i++) {
            k = i;
            for (j = i + 1; j < n; j++)
                if(r[j] < r[k]) k = j;
            sum = r[i];
            r[i] = r[k];
            r[k] = sum;
        }
        k = 0;
        sum = r[0];
        for (i = 1; i < n; i++) {
            if(sum >= r[i]) {
                k = 1;
                break;
            }
            sum += r[i];
        }
        puts(k ? "YES" : "NO");
    }
    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2719435   2008-01-04 17:04:56     Accepted    2811    C   00:00.02    388K    ¤ï¤¿¤·

// 2012-09-07 01:40:45 | Accepted | 2811 | C++ | 0 | 180 | watashi | Source
