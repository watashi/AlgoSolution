#include <math.h>
#include <stdio.h>
int main()
{
    int re,i,j,ii,jj,f[3],r[9];
    double  key,tmp,ans,eps,d;
    const double PI = 3.14159 ;

    scanf("%d",&re);
    while(re--){
        for(i=0;i<3;i++)
            scanf("%d",&f[i]);
        for(j=0;j<9;j++)
            scanf("%d",&r[j]);
        scanf("%lf%lf",&d,&key);
        d*=PI;
        eps=-1;
        for(i=0;i<3;i++)
            for(j=0;j<9;j++){
                tmp=d*f[i]/r[j];
                if(eps<0||fabs(tmp-key)<eps){
                    ii=i;jj=j;ans=tmp;eps=fabs(tmp-key);
                }
            }
        printf("A gear selection of %d/%d produces a gear size of %.3lf.\n",f[ii],r[jj],ans);
        if(re) printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2659621 2007-10-26 20:47:14 Accepted 1496 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 00:50:58 | Accepted | 1496 | C | 0 | 160 | watashi | Source
