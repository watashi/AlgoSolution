//solution for percent by whatashya@ZJU
#include <stdio.h>
char buf;
int main()
{
    while((buf = getchar()) != '#') {
        switch(buf) {
        case ' ': printf("%%20"); break;
        case '!': printf("%%21"); break;
        case '$': printf("%%24"); break;
        case '%': printf("%%25"); break;
        case '(': printf("%%28"); break;
        case ')': printf("%%29"); break;
        case '*': printf("%%2a"); break;
        default: putchar(buf);
        }
    }
}
/*
real    0m0.625s
user    0m0.046s
sys     0m0.280s
*/

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2768704 2008-03-03 16:33:58 Accepted 2932 C++ 00:00.00 388K わたし
//2768703 2008-03-03 16:33:45 Accepted 2932 C++ 00:00.00 392K わたし

// 2012-09-07 01:48:18 | Accepted | 2932 | C++ | 0 | 180 | watashi | Source
