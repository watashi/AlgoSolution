#include <stdio.h>
const double cw=4.19,ci=2.09,em=335;
int main()
{
    double mw,mi,tw,ti,q,m,t,x;

    while(scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti),mw+mi){
        m=mw+mi;t=100;
        q=((100-tw)*mw+100*mi)*cw+((-ti)*ci+em)*mi;
        x=100*cw*m;
        if(x>=q) {mw=m;mi=0;t=(1-q/x)*100;}
        else{
            q-=x;
            x=em*m;
            if(x>=q){mi=q/em;mw=m-mi;t=0;}
            else{
                q-=x;
                mw=0;mi=m;t=-q/(m*ci);
            }
        }
        printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n",mi,mw,t);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2601325 2007-09-08 18:56:37 Accepted 1981 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:07:49 | Accepted | 1981 | C | 0 | 160 | watashi | Source
