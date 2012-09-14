#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a>b)?a:b)
int comp(const int *a,const int *b)
{
    return (*a<*b)?-1:1;
}
int main()
{
    int i,j,k,tmp,temp,ans,c[24],p[24][24];

    while(scanf("%d%d",&i,&j),i!=-1){
        for(k=0;k<24;k++)
            c[k]=0;
        while(i){
            i--;j--;
            p[i][c[i]++]=j;
            scanf("%d%d",&i,&j);
        }
        for(k=0;k<24;k++)
            qsort(p[k],c[k],sizeof(int),comp);
        ans=0;
        for(k=0;k<24;k++){
            if(c[k]==0) continue;
            ans++;
            temp=p[k][c[k]-1];
            for(i=k+1;i<24;i++){
                if(c[i]==0) continue;/*!!!!!*/
                tmp=temp;
                temp=MAX(p[i][c[i]-1],temp);
                while(c[i]&&p[i][c[i]-1]>=tmp) c[i]--;
            }
        }
        printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2612570 2007-09-18 01:03:11 Accepted 1756 C 00:00.00 388K ¤ï¤¿¤· */

/*
<C++>
2612569.cpp: In function `int main()':
2612569.cpp:21: invalid conversion from `int
   (*)(const int*, const int*)' to `int (*)(const void*, const void*)'
*/

// 2012-09-07 03:04:43 | Accepted | 1756 | C | 0 | 160 | watashi | Source
