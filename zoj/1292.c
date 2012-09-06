#include <stdio.h>
#include <string.h>
int main()
{
    int ri,repeat,i,n,size,num[110],sum[110];
    char ch[110];

    scanf("%d\n\n",&repeat);
    for(ri=1;ri<=repeat;ri++){
        if(ri>1) printf("\n");
        for(i=0;i<110;i++)
            sum[i]=0;
        while(gets(ch),ch[0]!='0'||ch[1]!='\0'){
            size=strlen(ch);
            i=0;
            while(++i<=size){
                    sum[i]+=ch[size-i]-'0';
                    if(sum[i]>9){
                        sum[i]-=10;
                        sum[i+1]+=1;
                    }
            }
        }
        i=110;
        while(sum[--i]==0);
        for(;i>0;i--)
            printf("%d",sum[i]);
        printf("\n");
        getchar();
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2470995 2007-05-29 23:29:28 Accepted 1292 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 02:58:53 | Accepted | 1292 | C | 0 | 160 | watashi | Source
