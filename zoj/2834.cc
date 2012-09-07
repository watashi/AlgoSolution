#include <cstdio> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
struct Koopa{
    int t,ts,tp,tm;
    int n,a[1000];
}a[1000],root;
void doit(int k)
{
    int i,j,n=a[k].n;
    int s[1000],p[1000];
    int tmp,temp;

    a[k].ts=a[k].tp=a[k].tm=0;
    tmp=0;
    for(i=0;i<n;i++){
        doit(a[k].a[i]);
        s[i]=a[a[k].a[i]].ts;
        p[i]=a[a[k].a[i]].tp;
        a[k].ts+=s[i];
        tmp+=a[a[k].a[i]].tm;
    }
    if(n==1) a[k].tm=a[k].tp=a[k].ts;
    else{
        for(i=0;i<n;i++){
            temp=tmp-a[a[k].a[i]].tm;
            temp+=s[i];
            if(temp>a[k].tm) a[k].tm=temp;
            for(j=0;j<n;j++){
                if(i==j) continue;
                temp=tmp-a[a[k].a[i]].tm-a[a[k].a[j]].tm;
                temp+=s[i]+p[j];
                if(temp>a[k].tp) a[k].tp=temp;
            }
        }
    }
    a[k].ts+=a[k].t;
    a[k].tp+=a[k].t;
}
int main()
{
    int i,j,n,ans;

    while(scanf("%d",&n)!=EOF && n){
        for(i=0;i<n;i++){
            scanf("%d",&a[i].t);
            a[i].n=0;
        }
        root.n=0;
        for(i=0;i<n;i++){
            scanf("%d",&j);
            if(j==-1) root.a[root.n++]=i;
            else a[j].a[a[j].n++]=i;
        }
        ans=0;
        for(i=0;i<root.n;i++){
            doit(root.a[i]);
            if(root.a[i]==n-1) ans+=a[root.a[i]].tp;
            else ans+=a[root.a[i]].ts;
        }
        printf("%d\n",ans);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2677328 2007-11-15 23:21:51 Accepted 2834 C 00:00.05 12212K わたし



/*
13
1  2  3  4  5  6  7  8  9 10 11 12 13
6  6  6  7  7  7 12 12 12  8  9 10 -1
//81
*/
/*
一颗节点带权的树，每次可以任意访问一个未被访问过的节点，求访问到节点n - 1时的最
大权值和，限制条件是当某个节点有两个儿子被访问时，得立即访问该节点。

树形dp，关键是要理清整个过程，恰当表示各种状态。很显然在访问第二个儿子节点前应尽
可能多地访问其余节点。仔细观察可以发现，第一个儿子节点及其子树均可被访问，其余的
则必须在保证该节点不被访问的前提下最优化其子树。

如果用 last[v]表示最后访问节点v的最优解，
hold[v]表示以v为根的子树在不访问v的前提下的最优解
subTree[v]表示以v为根的子树的权值和

那么状态转移方程
last[v] = max(last[v1] + subTree[v2] + sum{ hold[v other] })
hold[v] = max(last[v1] + sum{ hold[v other] })

trick是有可能是森林, 有个队就郁闷在这里,pat~~~
*/

// 2012-09-07 14:11:10 | Accepted | 2834 | C++ | 20 | 4108 | watashi | Source
