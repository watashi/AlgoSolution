#include <stdio.h>
int a[17]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
int count;
void cut(int n,int x)
{
    int i;

    if(n==0){
        count++;
        return;
    }
    if(x==0){           /*don't forget*/
        count++;
        return;
    }
    for(i=0;i<=n;i++){
        if(x>=a[i]) cut(i,x-a[i]);/*>= not >*/
    }
}
int main()
{
    int x;

    while(scanf("%d",&x),x){
        count=0;
        cut(16,x);
        printf("%d\n",count);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2488120 2007-06-10 23:53:07 Accepted 1666 C 00:00.01 392K ¤ï¤¿¤· */

// 2012-09-07 00:57:29 | Accepted | 1666 | C | 0 | 160 | watashi | Source
