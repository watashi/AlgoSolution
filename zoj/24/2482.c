#include <stdio.h>
#include <math.h>
int main()
{
    int ri,i,j,n,sum,ip[4];
    char ch[35];

    scanf("%d\n",&n);
    for(ri=1;ri<=n;ri++){
        gets(ch);
        for(i=0;i<4;i++){
            ip[i]=0;
            for(j=0;j<8;j++)
                ip[i]+=(ch[8*i+j]-'0')*pow(2,7-j);
        }
        printf("%d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2477701 2007-06-03 05:00:59 Accepted 2482 C 00:00.01 2984K ¤ï¤¿¤· */

// 2012-09-07 03:10:52 | Accepted | 2482 | C | 0 | 160 | watashi | Source
