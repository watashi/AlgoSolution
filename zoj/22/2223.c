/* //不用二分图，直接贪心~ */
#include <stdio.h>
#include <string.h>
int card2int(char p[])
{
    int ret;

    switch(p[0]){
        case 'T':ret=40;break;
        case 'J':ret=44;break;
        case 'Q':ret=48;break;
        case 'K':ret=52;break;
        case 'A':ret=56;break;
        default:ret=(p[0]-'0')*4;break;
    }
    switch(p[1]){
        case 'C':break;
        case 'D':ret++;break;
        case 'S':ret+=2;break;
        case 'H':ret+=3;break;
    }
    return ret;
}
int a[60],b[60];
int main()
{
    char str[5];
    int re,i,j,k,n;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++){
            scanf("%s",str);
            a[card2int(str)]=1;
        }
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++){
            scanf("%s",str);
            b[card2int(str)]=1;
        }
        k=0;
        for(i=59;i>=8;i--)
            if(b[i]){   /*the cards must be different*/
                for(j=i-1;j>=8;j--)
                    if(a[j]){a[j]=0;k++;break;}
            }
        printf("%d\n",k);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2654520 2007-10-22 20:32:16 Accepted 2223 C 00:00.00 392K わたし */

// 2012-09-07 01:16:19 | Accepted | 2223 | C | 0 | 160 | watashi | Source
