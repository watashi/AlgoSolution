/* //32~127 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Blank 32
#define MAXN 96
int c[MAXN*MAXN],order[MAXN*MAXN];
int comp(const void *pa,const void *pb)
{
    int a=*(int *)pa,b=*(int *)pb;

    if(c[a]<c[b]) return 1;
    else if(c[a]>c[b]) return -1;
    else{
        if(a<b) return -1;
        else if(a>b) return 1;
    }
}
int main()
{
    char ch;
    int i,j,t,n,cc;

    while(scanf("%d",&n),n){
        getchar();
        for(i=0;i<MAXN*MAXN;i++){
            c[i]=0;
            order[i]=i;
        }
        cc=0;
        ch=getchar();
        i=(ch-Blank)*MAXN;
        while(n){
            ch=getchar();
            if(ch=='\n'){n--;continue;}
            j=ch-Blank;
            c[i+j]++;
            cc++;
            i=j*MAXN;
        }
        qsort(order,MAXN*MAXN,sizeof(int),comp);
        for(i=0;i<5;i++)
            printf("%c%c %d %lf\n",order[i]/MAXN+Blank,order[i]%MAXN+Blank,c[order[i]],(double)c[order[i]]/cc);
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2597150 2007-09-05 16:19:03 Accepted 1966 C 00:00.03 2984K ¤ï¤¿¤· */

// 2012-09-07 01:08:43 | Accepted | 1966 | C | 10 | 232 | watashi | Source
