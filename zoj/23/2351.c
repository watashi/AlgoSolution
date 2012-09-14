/* //k=(m*x)(n*x)/(c-x); */
/* //ans=-log10(m*x) */
#include <math.h>
#include <stdio.h>
int main()
{
    double k,c,x;
    int re,m,n;

    scanf("%d",&re);
    while(re--){
        while(scanf("%le%le%d%d",&k,&c,&m,&n),m&&n){
            x=(sqrt(k*k+4*k*c*m*n)-k)/(2*m*n);
            printf("%.3lf\n",-log10(m*x));
        }
        if(re) printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2630855 2007-10-03 22:19:47 Accepted 2351 C 00:00.15 400K ¤ï¤¿¤· */

// 2012-09-07 01:20:25 | Accepted | 2351 | C | 50 | 160 | watashi | Source
