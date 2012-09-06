#include <stdio.h>
#include <string.h>
int main()
{
    int i,n,j,l,x,y;
    double a,k,sum,z;
    char ch[20];

    while(scanf("%d\n",&n),n){
        sum=0.000;
        for(i=0;i<n;i++){
            gets(ch);
            l=strlen(ch);
            k=0.01;
            for(j=l-1;j>0;j--)
                if((l+1-j)%4){
                    sum+=(ch[j]-'0')*k;
                    k*=10;
                }
        }
        x=((int)sum)/1000000;
        y=((int)sum)/1000-x*1000;
        z=sum-x*1000000-y*1000;
        if(x) printf("$%d,%03d,%06.2lf\n",x,y,z);
        else if(y) printf("$%d,%06.2lf\n",y,z);
        else printf("$%.2lf\n",z);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2481509 2007-06-06 01:53:54 Accepted 2476 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:10:34 | Accepted | 2476 | C | 0 | 160 | watashi | Source
