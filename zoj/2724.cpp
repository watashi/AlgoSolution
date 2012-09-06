/*
#include <stdio.h>
typedef struct{
char msg[100];
int para,prio,time;
}cmd;
cmd a[60006];
int b[60006];
int n,time;

int comp(cmd *pa, cmd *pb)
{
return (pa->prio<pb->prio)?1:((pa->prio>pb->prio)?0:(pa->time<pb->time));
}

void insert()
{
int i,j,tmp;

scanf("%s%d%d",a[time].msg,&a[time].para,&a[time].prio);
//printf("%s %d\n",a[n].msg,a[n].para);//
a[time].time=time;
b[++n]=time++;
j=n;
i=n/2;
while(i&&comp(&a[b[j]],&a[b[i]])){
    tmp=b[i];
    b[i]=b[j];
    b[j]=tmp;
    j=i;
    i/=2;
}
}

void delmin()
{
int i,j,tmp;

if(n==0){printf("EMPTY QUEUE!\n");return;}
printf("%s %d\n",a[b[1]].msg,a[b[1]].para);
if(n==1){n=0;return;}
b[1]=b[n--];
i=1;
while((j=i+i)<=n){
    if(j<n&&comp(&a[b[j+1]],&a[b[j]])) j++;
    if(comp(&a[b[i]],&a[b[j]])) break;
    tmp=b[i];
    b[i]=b[j];
    b[j]=tmp;
    i=j;
}
}

int main()
{
char str[5];

n=0;
time=0;
while(scanf("%s",str)!=EOF){
//  printf("%s",str);//
    switch(str[0]){
    case 'G':delmin();break;
    case 'P':insert();break;
    }
}
}
*/
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2607267   2007-09-13 22:30:35     Accepted    2724    C++     00:00.31    7196K   わたし

#include <cstdio>
#include <set>
using namespace std;
const int MAXC=100;
class message{
private:
    int para,prio,index;
    char msg[MAXC];
public:
    void get() const
    {
        printf("%s %d\n",msg,para);
    }
    void put(int x)
    {
        scanf("%s%d%d",msg,&para,&prio);
        index=x;
    }
    bool operator<(const message &that) const
    {
        if(prio==that.prio) return index<that.index;
        else return prio<that.prio;
    }
};
int main()
{
    message cur;
    set<message> msg;
    char cmd[5];
    int index;

    index=0;
    while(scanf("%s",cmd)!=EOF){
        if(*cmd=='P'){
            cur.put(index++);
            msg.insert(cur);
        }
        else{
            if(msg.empty()) printf("EMPTY QUEUE!\n");
            else{
                cur=*msg.begin();
                cur.get();
                msg.erase(msg.begin());
            }
        }
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2607971 2007-09-14 16:13:42 Accepted 2724 C++ 00:00.30 3464K わたし

// 2012-09-07 01:36:11 | Accepted | 2724 | C++ | 110 | 2808 | watashi | Source
