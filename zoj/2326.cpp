#include <map>
#include <string>
#include <utility>
#include <iomanip>
#include <iostream>
using namespace std;
#define MAXN 500
#define inf 100e100
map<string,int> mp;
int m,n;
bool mark[MAXN];
double cmp,ans,board[MAXN][MAXN];
int main()
{
    while(cin>>cmp){
        cin>>n;
        mp.clear();
        for(int i=0;i<n;i++){
            string cur;
            cin>>cur;
            mp.insert(make_pair(cur,i));
            mark[i]=false;
            for(int j=0;j<n;j++)
                board[i][j]=inf;
        }
        cin>>m;
        while(m--){
            string cur;
            cin>>cur;
            int f=mp[cur];
            cin>>cur;
            int t=mp[cur];
            double d;
            cin>>d;
            board[f][t]=board[t][f]=d;
        }
        double ans=0;
        mark[0]=true;
        m=n;
        while(--m){
            int i,j,k;
            double w;
            k=-1;
            w=inf;
            for(i=0;i<n;i++){
                if(!mark[i]) continue;
                for(j=0;j<n;j++)
                    if(!mark[j]&&(k==-1||board[i][j]<w)){k=j;w=board[i][j];}
            }
            mark[k]=true;
            ans+=w;
        }
        if(ans<=cmp) cout<<"Need "<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)<<setprecision(1)<<ans<<" miles of cable"<<endl;
        else cout<<"Not enough cable"<<endl;
    }
}
//cout << setw(10) // 设定field宽度
//<< setprecision(5) // 设置小数位置
//<< setiosflags(ios::showpoint) // keep trailing 0s
//<< setiosflags(ios::fixed) // 使用这些设置
//<< d;

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2647025 2007-10-16 20:32:38 Accepted 2326 C++ 00:00.06 2804K わたし

// 2012-09-07 01:19:05 | Accepted | 2326 | C++ | 30 | 2140 | watashi | Source
