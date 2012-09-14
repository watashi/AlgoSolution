#include <stdio.h>
int main()
{
    char code[65][2],ch;
    int i,j,n;

    for(j=0;j<2;j++){
        i=0;
        while(scanf("%c",&code[i][j]))
            if(code[i++][j]=='\n') break;
        n=i-1;
    }
    for(j=1;j>=0;j--)
        for(i=0;i<=n;i++)
            printf("%c",code[i][j]);
    while(scanf("%c",&ch)!=EOF){
        for(i=0;i<=n;i++)
            if(ch==code[i][0]){
                printf("%c",code[i][1]);
                break;
            }
        if(i>n) printf("%c",ch);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2468893 2007-05-28 23:37:07 Accepted 1831 C 00:00.01 392K ¤ï¤¿¤· */

// 2012-09-07 03:05:20 | Accepted | 1831 | C | 0 | 160 | watashi | Source
