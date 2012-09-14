#include <stdio.h>
int main()
{
    int i,n,ri,repeat;
    char ch[71];

    scanf("%d\n",&repeat);
    for(ri=1;ri<=repeat;ri++){
        i=0;
        while((ch[i++]=getchar())!='\n');
        n=i-2;
        for(i=n;i>=0;i--)
            printf("%c",ch[i]);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469473 2007-05-29 12:14:51 Accepted 1295 C 00:00.00 392K わたし */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2461022 2007-05-24 21:21:19 Accepted 1295 C 00:00.01 392K わたし */

// 2012-09-07 02:58:59 | Accepted | 1295 | C | 0 | 160 | watashi | Source
