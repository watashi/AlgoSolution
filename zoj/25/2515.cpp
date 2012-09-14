#include <cstring> // auto fix CE
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define inf 999999999
class point{
private:
    int x,y,z;
public:
    point()
    {
        x=y=z=0;
    }
    void get()
    {
        scanf("%d%d%d",&x,&y,&z);
    }
    inline int height() const
    {
        return z;
    }
    inline bool operator ==(const point &that) const
    {
        return x==that.x&&y==that.y&&z==that.z;
    }
    inline bool operator <(const point &that) const
    {
        if(x==that.x){
            if(y==that.y) return z<that.z;
            else return y<that.y;
        }
        else return x<that.x;
    }
};
point p[2002];
map<point,int> mp;
bool board[2002][2002];
bool mark[2002];
int minh[2002];
void Dijkstra(int n,int s)
{
    int i,j,k;

    for(i=0;i<n;i++){
        minh[i]=inf;
        mark[i]=false;
    }
    minh[s]=p[s].height();
    for(i=0;i<n;i++){
        k=-1;
        for(j=0;j<n;j++)
            if(!mark[j]&&(k==-1||minh[j]<minh[k])) k=j;
        mark[k]=1;
        for(j=0;j<n;j++)
            if(!mark[j]&&board[k][j]&&max(minh[k],p[j].height())<minh[j]) minh[j]=max(minh[k],p[j].height());
    }
}
int main()
{
    int n,m,ff,tt,ans;
    point f,t;

    while(scanf("%d",&m)!=EOF){
        memset(board,0,sizeof(board));
        mp.clear();
        mp.insert(make_pair(point(),0));
        p[0]=point();
        n=1;
        while(m--){
            f.get();
            t.get();
            if(mp.find(f)==mp.end()){
                mp.insert(make_pair(f,n));
                p[n]=f;
                ff=n++;
            }
            else ff=mp[f];
            if(mp.find(t)==mp.end()){
                mp.insert(make_pair(t,n));
                p[n]=t;
                tt=n++;
            }
            else tt=mp[t];
            board[ff][tt]=board[tt][ff]=true;
        }
        Dijkstra(n,0);
        ans=p[0].height();
        scanf("%d",&m);
        while(m--){
            t.get();
            tt=mp[t];
            if(minh[tt]>ans) ans=minh[tt];
        }
        printf("%d\n",ans);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2646787 2007-10-16 16:25:02 Accepted 2515 C++ 00:00.42 4816K ¤ï¤¿¤·

// 2012-09-07 13:36:16 | Accepted | 2515 | C++ | 140 | 4128 | watashi | Source
