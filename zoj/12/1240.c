#include <stdio.h>
int main()
{
    int i,ri,repeat;
    /* char ch[40]; */
    char ch[80];

    scanf("%d\n",&repeat);
    for(ri=1;ri<=repeat;ri++){
        i=0;
        while((ch[i++]=getchar())!='\n');
        i=0;
        printf("String #%d\n",ri);
        while(ch[i]!='\n'){
            if(ch[i]=='Z') ch[i]='A'-1;
            printf("%c",ch[i++]+1);
        }
        printf("\n\n");
    }

    return 0;   /* NZEC */
}
/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2461008 2007-05-24 21:15:37 Accepted 1240 C 00:00.00 388K わたし */
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469463 2007-05-29 12:11:56 Accepted 1240 C 00:00.00 392K わたし */

/* 2012-09-07 14:19:04 | Segmentation Fault | 1240 | C | 0 | 0 | watashi | Source */

// 2012-09-07 14:22:06 | Accepted | 1240 | C | 0 | 160 | watashi | Source
