#include <stdio.h>
#include <string.h>
const int g=34943;
const int bit=1<<8;
int main()
{
    int i,r;
    char msg[1111];

    while(gets(msg) && *msg!='#'){
        r=0;
        for(i=0;msg[i];i++){
            r*=bit;
            r+=msg[i];
            r%=g;
        }
        r*=bit;r%=g;
        r*=bit;r%=g;
        if(r) r=g-r;
        printf("%02X %02X\n",r/bit,r%bit);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2633130 2007-10-05 16:12:02 Accepted 1164 C 00:00.01 392K わたし */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2633131 2007-10-05 16:12:31 Accepted 1164 C 00:00.00 388K わたし */

// 2012-09-07 02:57:10 | Accepted | 1164 | C | 0 | 160 | watashi | Source
