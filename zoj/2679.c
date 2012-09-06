#include <stdio.h>
int main()
{
    int re,n,a,b,c,i,j,x;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d%d%d",&n,&a,&b,&c);
        a=1000*a+100*b+10*c;
        for(i=9;i;i--){
            x=10000*i+a;
            for(j=x+9;j>=x;j--)
                if(j%n==0) break;
            if(j>=x) break;
        }
        if(i) printf("%d %d %d\n",i,j%10,j/n);
        else printf("0\n");
    }
}
/* //2548591 2007-08-01 23:31:17 Accepted 2679 C 00:00.06 388K ¤ï¤¿¤· */

// 2012-09-07 01:34:33 | Accepted | 2679 | C | 20 | 160 | watashi | Source
