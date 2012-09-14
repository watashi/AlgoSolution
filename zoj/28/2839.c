#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ans{
    int a,b;
}ansl[150000];
int ansn;
int trin,tril[1500];
char tri[255000];
int cmp(const void *pa,const void *pb)
{
    if(((struct ans*)pa)->b==((struct ans*)pb)->b) return (((struct ans*)pa)->a<((struct ans*)pb)->a)?-1:1;
    else return (((struct ans*)pa)->b<((struct ans*)pb)->b)?-1:1;
}
int main()
{
    int ri,i,j,k,b,t,n,m;

    memset(tri,0xff,sizeof(tri));
    for(i=0;i<=50;i++){
        b=i*i*i;
        for(j=0;j<=i;j++){
            t=b+j*j*j;
            if(tri[t]==-1||tri[t]>i) tri[t]=i;
        }
    }
    trin=0;
    for(k=0;k<255000;k++)
        if(tri[k]!=-1) tril[trin++]=k;
    ri=0;
    while(scanf("%d%d",&n,&m)!=EOF && n||m){
        if(ri) putchar('\n');
        ansn=0;
        for(i=0;i<trin;i++){
            if(tri[tril[i]]>m) continue;
            for(j=i+1;j<trin;j++){
                if(tri[tril[j]]>m) continue;
                else{
                    b=tril[j]-tril[i];
                    t=tril[j]+b;
                }
                for(k=2;k<n&&t<255000;k++){
                    if(tri[t]==-1||tri[t]>m) break;
                    else t+=b;
                }
                if(k==n){
                    ansl[ansn].a=tril[i];
                    ansl[ansn].b=b;
                    ansn++;
                }
            }
        }
        printf("Case %d:\n",++ri);
        if(ansn){
            qsort(ansl,ansn,sizeof(struct ans),cmp);
            for(k=0;k<ansn;k++)
                printf("%d %d\n",ansl[k].a,ansl[k].b);
        }
        else printf("NONE\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2680052 2007-11-19 13:57:20 Accepted 2839 C 00:00.10 1816K わたし */
/* //2680051 2007-11-19 13:57:10 Accepted 2839 C++ 00:00.09 1868K わたし */

// 2012-09-07 03:13:37 | Accepted | 2839 | C | 60 | 1584 | watashi | Source
