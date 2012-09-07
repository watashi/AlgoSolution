/*忽略第一二个的组合*/
/*
10  0110    01  11  10
11  0101    01  10  01
01  1001    10  00  01
00  1010    10  01  10
*/
/*
#include <cstdio> // auto fix CE
#include <stdio.h>
#define MAXL 34
#define c_00 0
#define c_01 1
#define c_10 2
#define c_11 3
typedef struct count{
    long num[MAXL];
    int n;
}Count;
Count tt,*ptt=&tt;
Count *add(Count *pa,Count *pb)
{
    int i;

    for(i=0;i<MAXL;i++){
        ptt->num[i]=pa->num[i]+pb->num[i];
        if(i&&ptt->num[i-1]>1000000000){
            ptt->num[i]++;
            ptt->num[i-1]-=1000000000;
        }
    }
    return ptt;
}
void Print(Count *p)
{
    int i;

    i=MAXL;
    while(!p->num[--i]);
    printf("%ld",p->num[i]);
    while(i>0)
        printf("%09ld",p->num[--i]);
    printf("\n");
}
int main()
{
    int i,n,cc;
    struct count a[4],b[4],*pa,*pb,*pt;

    while(scanf("%d",&n)!=EOF){
        pa=a;
        pb=b;
        for(i=0;i<MAXL;i++)
            a[1].num[i]=a[2].num[i]=a[3].num[i]=a[0].num[i]=0;
        cc=c_01;
        for(i=1;i<=n;i++){
            *(pb+c_00)=*(pa+c_01);
            *(pb+c_01)=*add(add((pa+c_00),(pa+c_01)),(pa+c_11));
            *(pb+c_10)=*add(add((pa+c_00),(pa+c_10)),(pa+c_11));
            *(pb+c_11)=*(pa+c_10);
            ((pb+cc)->num[0])++;
            cc=3-cc;
            pt=pa;
            pa=pb;
            pb=pt;
        }
        if(n>1) Print(pa+c_00);
        else printf("0\n");
    }
}
//da shu hao fan
//TLE
*/
#include <cstdio> // auto fix CE
#include <stdio.h>
#define MAXL 40
#define c_10 0
#define c_01 1
#define c_00 2
#define c_11 3
typedef struct count{
    long num[MAXL];
    int n;
}Count;
void add(Count *pa,Count *pb,Count *pt)
{
    int i,n;

    if(pa==NULL){
        i=0;
        while(++pt->num[i]>=1000000000) pt->num[i++]-=1000000000;
        if(i==pt->n) pt->num[++pt->n]=0;
    }
    else{
        n=(pa->n>pb->n)?pa->n:pb->n;
        pt->num[0]=0;
        for(i=0;i<n;i++){
            pt->num[i+1]=0;
            pt->num[i]+=pa->num[i]+pb->num[i];
            if(pt->num[i]>=1000000000){
                pt->num[i+1]++;
                pt->num[i]-=1000000000;
            }
        }
        if(pt->num[n]) pt->num[++n]=0;
        pt->n=n;
    }
}
void Print(Count *p)
{
    int i;

    i=p->n-1;
    printf("%ld",p->num[i]);
    while(i>0)
        printf("%09ld",p->num[--i]);
    printf("\n");
}
int main()
{
    int i,n,cc;
    Count a[2][1001],t,*pt=&t;

    a[c_01][0].num[0]=0;a[c_01][0].num[1]=0;a[c_01][0].n=1;
    a[c_10][0].num[0]=0;a[c_10][0].num[1]=0;a[c_10][0].n=1;
    a[c_01][1].num[0]=1;a[c_01][1].num[1]=0;a[c_01][1].n=1;
    a[c_10][1].num[0]=0;a[c_10][1].num[1]=0;a[c_10][1].n=1;
    cc=c_10;
    for(i=2;i<1001;i++){
        add(&a[c_01][i-2],&a[c_10][i-2],pt);
        add(pt,&a[c_01][i-1],&a[c_01][i]);
        add(pt,&a[c_10][i-1],&a[c_10][i]);
        add(NULL,NULL,&a[cc][i]);/*a[cc][i].num[0]+=1;*/
        cc=!cc;
    }
    while(scanf("%d",&n)!=EOF){
        if(n>0) Print(&a[c_01][n-1]);
        else printf("0\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2517783 2007-07-13 23:26:50 Accepted 2584 C 00:00.16 712K わたし

// 2012-09-07 14:10:46 | Accepted | 2584 | C++ | 40 | 180 | watashi | Source
