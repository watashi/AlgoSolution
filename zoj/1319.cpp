//pjn一定会说线段树~~~~ ^_^
/*
  2    #include <cstdio>
  3    #include <queue>
  4    #include <vector>
  5    #include <functional>
  6
  7    using namespace std;
  8
  9    const int size = 30000;
 10    int add[size], get[size];
 11
 12    int main() {
 13         int cases;
 14         scanf("%d", &cases);
 15         for (int i = 0; i < cases; ++i){
 16              if (i)
 17               putchar('\n');
 18              int m, n;
 19              scanf("%d%d", &m, &n);
 20              for (int i = 0; i < m; ++i)
 21               scanf("%d", &add[i]);
 22              for (int i = 0; i < n; ++i)
 23               scanf("%d", &get[i]);
 24              priority_queue < int, vector<int>, less<int> > front;
 25              priority_queue < int, vector<int>, greater<int> > rear;
 26              int i = 0;
 27              for (int j = 0; j < m; ++j) {
 28                   for (; get[i] == j; ++i) {// for (; i<n && get[i] == j; ++i)
 29                        printf("%d\n", rear.top());
 30                        front.push(rear.top());
 31                        rear.pop();
 32                   }
 33                   if (front.empty() || front.top() < add[j])
 34                    rear.push(add[j]);
 35                   else {
 36                        rear.push(front.top());
 37                        front.pop();
 38                        front.push(add[j]);
 39                   }
 40              }
 41              while (i++ < n) {
 42                   printf("%d\n", rear.top());
 43                   rear.pop();
 44              }
 45         }
 46         return 0;
 47    }
 //cc98
[quote="我不是女孩"]ray[/quote]
//2626279 2007-09-30 19:10:14 Accepted 1319 C++ 00:00.21 1084K わたし
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
#define MAXN 30003
int a[MAXN],u[MAXN];
int main()
{
    int re,i,j,n,m,t;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(j=0;j<n;j++)
            scanf("%d",&u[j]);
        priority_queue < int, vector<int>, less<int> > front;
        priority_queue < int, vector<int>, greater<int> > rear;
        int j=0;
        for(i=0;i<=m;i++){//i<=m
            while(j<n&&u[j]==i){
                t=rear.top();
                printf("%d\n",t);
                rear.pop();
                front.push(t);
                j++;
            }
            if(i==m) continue;//
            if(front.empty()||a[i]>=front.top()) rear.push(a[i]);
            else{
                rear.push(front.top());
                front.pop();
                front.push(a[i]);
            }
        }
        if(re) printf("\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2626436 2007-09-30 21:25:41 Accepted 1319 C++ 00:00.20 1084K わたし
//2626435 2007-09-30 21:24:34 Presentation Error 1319 C++ 00:00.20 1080K わたし
/*
10 2006-10-27 16:19:04 00:00.20 960K C++ Lampard
11 2007-09-30 19:44:47 00:00.20 1084K C++ ray
12 2007-09-30 21:25:41 00:00.20 1084K C++ わたし
13 2007-09-30 19:41:38 00:00.20 1212K C++ piapia
*/

// 2012-09-07 00:45:42 | Accepted | 1319 | C++ | 70 | 672 | watashi | Source
