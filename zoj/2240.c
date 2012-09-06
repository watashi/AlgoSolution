#include <stdio.h>
#include <string.h>
char str[1024];
int main()
{
    int i, j, k;

    while(gets(str)) {
        i = 0;
        while(str[i]) {
            if(str[i] == str[i + 1]) {
                for (j = 2; j < 9; j++)
                    if(str[i + j] != str[i]) break;
                putchar('0' + j);
                putchar(str[i]);
                i = i + j;
            } else {
                j = i + 1;
                while(str[j] && str[j] != str[j + 1]) j++;
                putchar('1');
                for (k = i; k < j; k++) {
                    putchar(str[k]);
                    if(str[k] == '1') putchar('1');
                }
                putchar('1');
                i = j;
            }
        }
        putchar('\n');
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2720179 2008-01-05 22:55:34 Accepted 2240 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 01:16:50 | Accepted | 2240 | C | 0 | 160 | watashi | Source
