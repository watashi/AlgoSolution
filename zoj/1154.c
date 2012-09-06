#include <stdio.h>
int main()
{
    int ri,repeat,base,sum;
    long num,x;
    char ch;

    scanf("%d",&repeat);
    for(ri=1;ri<=repeat;ri++){
        if(ri>1) printf("\n");
        while(scanf("%d",&base),base){
            getchar();
            num=sum=0;
            while((ch=getchar())!='\n'){
                num=base*num+ch-'0';
                sum+=ch-'0';
            }
            if(num%sum==0) printf("yes\n");
            else printf("no\n");
        }
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2472168 2007-05-30 18:38:02 Accepted 1154 C 00:00.02 392K ¤ï¤¿¤· */

// 2012-09-07 00:39:17 | Accepted | 1154 | C | 0 | 160 | watashi | Source
