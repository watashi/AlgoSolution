#include <stdio.h>
#include <math.h>
int prime(int a,int b)
{
    int t;

    if(a<b){
        t=a;
        a=b;
        b=t;
    }
    while(a%b!=0){
        t=b;
        b=a%b;
        a=t;
    }
    if(b==1) return 1;
    else return 0;
}
int main()
{
    int n,i,j,a[50];
    double r,s;

    while(scanf("%d",&n),n){
        r=s=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            for(j=0;j<i;j++){
                s++;
                if(prime(a[i],a[j])) r++;
            }
        }
        if(r) printf("%.6lf\n",sqrt(6.0*s/r));
        else printf("No estimate for this data set.\n");
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469481 2007-05-29 12:19:52 Accepted 1337 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 02:59:48 | Accepted | 1337 | C | 0 | 160 | watashi | Source
