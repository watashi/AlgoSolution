#include <stdio.h>
int main()
{
    int keep,a,b,i,j,k1,k2,mod[55]={0,1,1};
    long n;

    while(scanf("%d%d%ld",&a,&b,&n),a){
        keep=1;
        for(i=3;keep;i++){
            mod[i]=(a*mod[i-1]+b*mod[i-2])%7;
            for(j=2;j<i;j++)
                if(mod[j-1]==mod[i-1]&&mod[j]==mod[i]){
                    keep=0;
                    break;
                }
        }
        k2=i-2;
        k1=j-1;
        if(n<k1) printf("%d\n",mod[n]);
        else printf("%d\n",mod[(n-k1)%(k2-k1)+k1]);
    }
}
/* //2487849 2007-06-10 17:54:17 Accepted 2105 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 01:13:00 | Accepted | 2105 | C | 0 | 160 | watashi | Source
