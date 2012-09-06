//solution for eds by whatashya@ZJU
#include <stdio.h>
char usr[32], buf[32];
int log[26];
int main()
{
    int ri = 0;
    int i, j, k;
    char c;

    while(1) {
        for (i = 0; i < 26; i++)
            log[i] = 0;
        while(1) {
            if(scanf("%[A-Z]%c%[a-z]", usr, &c, buf) != 3) return 0;
            k = 0;
            for (i = 0; buf[i]; i++)
                k |= (1 << buf[i] - 'a');
            switch(c) {
            case '+':
                for (i = 0; usr[i]; i++)
                    log[usr[i] - 'A'] |= k;
                break;
            case '-':
                for (i = 0; usr[i]; i++)
                    log[usr[i] - 'A'] &= ~k;
                break;
            case '=':
                for (i = 0; usr[i]; i++)
                    log[usr[i] - 'A'] = k;
                break;
            }
            if(getchar() == '\n') break;
        }
        printf("%d:", ++ri);
        k = 0;
        for (i = 0; i < 26; i++) {
            if(log[i] == 0) continue;
            if(k && log[i] != k) {
                for (j = 0; j < 26; j++)
                    if(k & (1 << j)) putchar('a' + j);
            }
            putchar('A' + i);
            k = log[i];
        }
        if(k) {
            for (j = 0; j < 26; j++)
                if(k & (1 << j)) putchar('a' + j);
        }
        putchar('\n');
    }
}
/*
real    0m0.453s
user    0m0.077s
sys     0m0.234s
*/

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2768718 2008-03-03 16:41:55 Accepted 2936 C++ 00:00.00 388K ¤ï¤¿¤·

// 2012-09-07 01:48:42 | Accepted | 2936 | C++ | 0 | 180 | watashi | Source
