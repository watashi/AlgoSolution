#include <stdio.h>
int main()
{
    struct _register{
        int id,pe;
        long t;
    }q[1000],t;
    char cc[20];
    int i,j,index,n,k;

    n=0;
    while(scanf("%s",cc),cc[0]!='#'){
        scanf("%d %d",&q[n].id,&q[n].pe);
        q[n].t=q[n].pe;
        n++;
    }
    scanf("%d",&k);
    for(i=0;i<n;i++){
        index=i;
        for(j=i+1;j<n;j++)
            if(q[j].id<q[index].id) index=j;
        t=q[index];q[index]=q[i];q[i]=t;
    }
    while(k--){
        index=0;
        for(i=1;i<n;i++)
            if(q[i].t<q[index].t) index=i;
        printf("%d\n",q[index].id);
        q[index].t+=q[index].pe;
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2508713 2007-07-03 23:25:26 Accepted 2212 C 00:00.06 404K ¤ï¤¿¤· */

// 2012-09-07 01:16:07 | Accepted | 2212 | C | 20 | 160 | watashi | Source
