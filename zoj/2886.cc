#include <stdio.h>
int main()
{
    int re;
    int i, j, cnt;
    char str[1001];

    scanf("%d ", &re);
    while(re--) {
        gets(str);
        for (i = 0; str[i]; i = j) {
            j = i;
            do {j++; } while (str[j] == str[i]);
            printf("%d%c", j - i, str[i]);
        }
        putchar('\n');
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2717858 2008-01-01 21:30:03 Accepted 2886 C 00:00.22 396K わたし

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//82 2007-12-26 22:48:37 Accepted 1011 C 00:00:22 396K わたし

/*
#include <cstdio>

char str[1001];

int main() {
    int t;
    for (scanf("%d", &t); t > 0; t--) {
        scanf("%s", str);
        for (int i = 0; str[i] != '\0'; i++) {
            int num = 1;
            while (str[i + 1] == str[i]) {
                num++;
                i++;
            }
            printf("%d%c", num, str[i]);
        }
        putchar('\n');
    }

    return 0;
}
//Fire
*/

// 2012-09-07 14:11:28 | Accepted | 2886 | C++ | 90 | 180 | watashi | Source
