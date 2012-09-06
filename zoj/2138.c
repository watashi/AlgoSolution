#include <stdio.h>
int main()
{
    int re;
    int i,j,n,p,cr[100][100],q[100],min,max;

    scanf("%d",&re);
    while(--re>=0){
        scanf("%d%d",&n,&p);
        for(i=0;i<p;i++)
            q[i]=0;
        for(i=0;i<n;i++){
            min=1000;
            max=0;
            for(j=0;j<p;j++){
                scanf("%d",&cr[i][j]);
                if(cr[i][j]>max) max=cr[i][j];
                if(cr[i][j]<min) min=cr[i][j];
            }
            for(j=0;j<p;j++){
                if(cr[i][j]==max) q[j]=-100;
                if(cr[i][j]==min) q[j]++;
            }
        }
        n/=2;
        for(i=j=0;i<p;i++)
            if(q[i]>n){
                if(j) printf(" %d",i+1);
                else {printf("%d",i+1);j=1;}
            }
        if(!j) printf("0\n");
        else printf("\n");
        if(re) printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2508814 2007-07-04 10:50:15 Accepted 2138 C 00:00.01 432K ¤ï¤¿¤· */

// 2012-09-07 03:08:44 | Accepted | 2138 | C | 0 | 160 | watashi | Source
