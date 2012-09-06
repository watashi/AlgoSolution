#include <stdio.h>
int main()
{
    char ch,i=0;

    while(scanf("%c",&ch)!=EOF){
        switch(ch){
        case 'B':case 'F':case 'P':case 'V':
            if(i-1) printf("1");i=1;break;
        case 'C':case 'G':case 'J':case 'K':
        case 'Q':case 'S':case 'X':case 'Z':
            if(i-2) printf("2");i=2;break;
        case 'D':case 'T':
            if(i-3) printf("3");i=3;break;
        case 'L':
            if(i-4) printf("4");i=4;break;
        case 'M':case 'N':
            if(i-5) printf("5");i=5;break;
        case 'R':
            if(i-6) printf("6");i=6;break;
        case '\n':
            printf("\n");i=0;break;
        default:
            i=0;break;
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2468878 2007-05-28 23:17:45 Accepted 1858 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:05:38 | Accepted | 1858 | C | 0 | 160 | watashi | Source
