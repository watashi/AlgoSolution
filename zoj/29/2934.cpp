//solution for bits by whatashya@ZJU
#include <stdio.h>
#include <string.h>
#define MAXN 65536
char mark[MAXN];
int a, b, c, s;
int main()
{
    int x, And, Or, Xor;

    while(scanf("%d%d%d%d", &a, &b, &c, &s) == 4) {
        memset(mark, 0, sizeof(mark));
        And = MAXN - 1;
        Or = 0;
        x = s;
        while(!mark[x]) {
            mark[x] = 1;
            And &= x;
            Or |= x;
            x = (a * x + b) % c;
        }
        Xor = And ^ Or;
        for (x = MAXN >> 1; x; x >>= 1) {
            if(Xor & x) putchar('?');
            else if(Or & x) putchar('1');
            else putchar('0');
        }
        putchar('\n');
    }
}
/*
real    0m0.532s
user    0m0.030s
sys     0m0.327s
*/

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2768714 2008-03-03 16:38:57 Accepted 2934 C++ 00:00.00 452K ¤ï¤¿¤·

// 2012-09-07 01:48:30 | Accepted | 2934 | C++ | 0 | 244 | watashi | Source
