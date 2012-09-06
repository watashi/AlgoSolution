#include <stdio.h>
int main()
{
    int re,i,n,a[21][2],m,t,c,temp,max;

    re=0;
    while(scanf("%d%d%d",&n,&m,&c),n){
        for(i=1;i<=n;i++){
            scanf("%d",&a[i][0]);
            a[i][1]=0;
        }
        max=temp=0;
        for(i=1;i<=m;i++){
            scanf("%d",&t);
            if(a[t][1]){
                temp-=a[t][0];
                a[t][1]=0;
            }
            else{
                temp+=a[t][0];
                a[t][1]=1;
            }
            if(temp>max) max=temp;
        }
        if(max>c) printf("Sequence %d\nFuse was blown.\n\n",++re);
        else printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",++re,max);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2501734 2007-06-24 12:50:43 Accepted 1195 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 02:57:34 | Accepted | 1195 | C | 0 | 160 | watashi | Source
