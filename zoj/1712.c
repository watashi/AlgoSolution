#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char ch[35];
    long x,i,n;

    while(x=0,gets(ch),ch[i=0]!='0'){
        n=strlen(ch);
        for(i=0;i<n;i++)
            x+=(ch[i]-'0')*(pow(2,n-i)-1);
        printf("%ld\n",x);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2475832 2007-06-02 02:04:09 Accepted 1712 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 03:04:01 | Accepted | 1712 | C | 0 | 160 | watashi | Source
