#include <stdio.h>
int main()
{
    int a,b,i,count;

    while(scanf("%d%d",&a,&b),a+b){
        count=0;
        while(a&&b){
            if(a<b){i=a;a=b;b=i;}
            i=a/b;
            a%=b;
            if(a==0||i>1) break;
            else count++;
        }
        if(count%2) printf("Ollie wins\n");
        else printf("Stan wins\n");
    }
}
/* ////****good! i can't believe it myself */
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2530163 2007-07-22 19:01:27 Accepted 1913 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 01:06:01 | Accepted | 1913 | C | 0 | 160 | watashi | Source
