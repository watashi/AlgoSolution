#include <stdio.h>
void printit(int x,int b)
{
    if(x>=b) printit(x/b,b);
    printf("%d",x%b);
}
int main()
{
    int i;
    char p[1001],m[11];
    long long b,mod,ret;

    while(scanf("%lld%s%s",&b,p,m)==3 && b){
        mod=0;
        for(i=0;m[i];i++){
            mod*=b;
            mod+=m[i]-'0';
        }
        ret=0;
        for(i=0;p[i];i++){
            ret*=b;
            ret+=p[i]-'0';
            if(ret>=mod) ret%=mod;
        }
        if(ret==0) printf("0");
        else printit(ret,b);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2651875 2007-10-20 16:28:53 Accepted 1929 C 00:00.01 396K ¤ï¤¿¤· */

// 2012-09-07 03:07:06 | Accepted | 1929 | C | 0 | 160 | watashi | Source
