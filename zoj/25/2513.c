#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long Time;
typedef struct status{
    int n;
    Time t;
}Status;
typedef struct record{
    char id[31];
    int ac;
    Status s[10];
    Time t;
}Record;
Time gettime()
{
    char cc;
    int hh,mm,ss;

    scanf("%d%c",&hh,&cc);
    if(cc!=':'){
        return hh;
    }
    else{
        scanf("%d:%d",&mm,&ss);
        return 3600*hh+60*mm+ss;
    }
}
Status getstatus()
{
    Time t;
    Status x;

    t=gettime();
    if(t<=0){
        x.t=0;
        x.n=t;
    }
    else{
        x.t=t;
        while(getchar()!='(');
        scanf("%d",&x.n);
        while(getchar()!=')');
    }
    return x;
}
Record getrecord(int m)
{
    int i;
    Record x;

    scanf("%d%s%d",&i,x.id,&x.ac);
    for(i=0;i<m;i++)
        x.s[i]=getstatus();
    x.t=gettime();
    return x;
}
int compare(const void *pa,const void *pb)
{
    Record *a=(Record *)pa,*b=(Record *)pb;

    if(a->ac==b->ac){
        if(a->t==b->t){
            return (strcmp(a->id,b->id)<0)?-1:1;
        }
        else return (a->t<b->t)?-1:1;
    }
    else return (a->ac>b->ac)?-1:1;
}
void puttime(Time t)
{
    int hh,mm,ss;

    hh=t/3600;
    mm=t/60%60;
    ss=t%60;
    printf("%02d:%02d:%02d",hh,mm,ss);
}
void putstatus(Status *p)
{
    if(p->t==0) printf("%d ",p->n);
    else{
        puttime(p->t);
        printf(" (%d) ",p->n);
    }
}
void putrecord(Record a[],int n,int m)
{
    int i,j,k;

    k=1;
    for(i=0;i<n;i++){
        if(i&&a[i].ac==a[i-1].ac&&a[i].t==a[i-1].t) k--;
        printf("%d %s %d ",k++,a[i].id,a[i].ac);
        for(j=0;j<m;j++)
            putstatus(&a[i].s[j]);
        puttime(a[i].t);
        printf("\n");
    }
}
int main()
{
    Record a[3001];
    int i,n,m,t,ac[11],blank=0;

    while(scanf("%d%d",&n,&m)!=EOF){
        if(blank) printf("\n");
        else blank=1;
        for(i=0;i<=m;i++)
            ac[i]=0;
        i=0;
        while(n--){
            scanf("%d",&t);
            while(t--){
                a[i]=getrecord(m);
                ac[a[i].ac]++;
                i++;
            }
        }
        t=i;
        qsort(a,t,sizeof(Record),compare);
        putrecord(a,t,m);
        printf("Total Teams: %d",t);
        for(i=m;i;i--)
            if(ac[i]) printf("; Solved %d: %d",i,ac[i]);
        printf(".\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2646723 2007-10-16 15:31:46 Accepted 2513 C 00:00.01 824K わたし */
/*
Rank Submit time Run time Run memory Language User
1 2006-02-02 14:51:34 00:00.00 1388K C++ wcm
2 2006-04-04 18:58:51 00:00.00 1696K C++ scau_dawn
3 2006-04-10 17:37:33 00:00.00 1696K C++ ltiger
4 2005-09-24 11:30:43 00:00.01 524K C++ SHOIT
5 2006-03-26 22:48:53 00:00.01 752K C++ Johnny
6 2007-10-16 15:31:46 00:00.01 824K C わたし
7 2006-02-06 13:46:33 00:00.01 960K C++ Ronin
8 2006-10-05 13:11:14 00:00.01 1036K C++ aaaaaaaaa
9 2006-08-08 14:24:21 00:00.01 1080K C++ Wonderful
10 2005-09-17 17:39:04 00:00.01 1088K C++ van
11 2005-09-15 22:18:48 00:00.01 1092K C++ 阿九
12 2006-04-11 17:13:54 00:00.01 1148K C++ KK
13 2006-04-11 17:14:16 00:00.01 1148K C++ scau_fantasy
14 2007-10-15 11:01:01 00:00.01 1692K C++ ÅÆÇ
15 2006-04-03 21:57:20 00:00.01 1696K C++ sun
16 2005-09-20 16:52:52 00:00.01 1700K C++ 薛在岳
17 2005-09-17 00:40:53 00:00.02 604K FPC Huang WenHao
*/

// 2012-09-07 04:56:27 | Accepted | 2513 | C | 0 | 164 | watashi | Source
