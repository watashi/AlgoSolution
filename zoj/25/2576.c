#include <stdio.h>
int n, a[22];
void dfs(int index, int temp, int rest)
{
    int i;

    for (i = temp; i + i <= rest; i++) {
        a[index] = i;
        dfs(index + 1, i, rest - i);
    }
    if(rest <= n){
        putchar('{');
        for (i = 0; i < index; i++)
            printf("%d,", a[i]);
        printf("%d}\n", rest);
    }
}
int main()
{
    while(scanf("%d", &n) != EOF && n) {
        dfs(0, 1, n + n);
        putchar('\n');
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2722624 2008-01-10 15:04:13 Accepted 2576 C 00:00.02 388K ¤ï¤¿¤· */

// 2012-09-07 01:29:44 | Accepted | 2576 | C | 10 | 160 | watashi | Source
