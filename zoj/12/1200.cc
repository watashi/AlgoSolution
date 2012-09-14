#include <cstdio> // auto fix CE
#include <stdio.h>
int pq[11111],p,tail;
int top()
{
    return pq[1];
}
void pop_push(int x)
{
    int i,t;

    pq[i=1]=x;
    while(2*i<tail){
        if(pq[i]<=pq[2*i]&&(2*i+1==tail||pq[i]<=pq[2*i+1])) break;
        else if(2*i+1==tail||pq[2*i]<=pq[2*i+1]) {t=pq[i];pq[i]=pq[2*i];pq[2*i]=t;i=2*i;}
        else {t=pq[i];pq[i]=pq[2*i+1];pq[2*i+1]=t;i=2*i+1;}
    }
}
int main()
{
    int s,w,c,k,m,tmp,time,rest;

    while(scanf("%d%d%d%d%d",&s,&w,&c,&k,&m)!=EOF){
        if(k>10010) k=10010;//Runtime Error     SIGSEGV
        for(tail=1;tail<=k;tail++)
            pq[tail]=tail*m+s;
        rest=10000;
        time=0;
        while(rest>0){
            tmp=top();
            if(time<tmp) time=tmp;
            time+=w;
            pop_push(time+2*s);
            rest-=c;
            p++;
        }
        printf("%d\n",time+s);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2655421 2007-10-23 16:33:06 Accepted 1200 C 00:00.00 432K ¤ï¤¿¤·

// 2012-09-07 14:08:22 | Accepted | 1200 | C++ | 0 | 224 | watashi | Source
