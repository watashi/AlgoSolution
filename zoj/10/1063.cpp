#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <stdio.h>
#include <string.h>
char a[62][62][62];
int n,m,k;
const int d[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int p;
struct pos{
    int x,y,z;
}q[62*62*62];
int isacm(int x,int y,int z)
{
    if(x<0||y<0||z<0||x>n+1||y>m+1||z>k+1) return 0;
    else return a[x][y][z];
}
int main()
{
    int l,x,y,z,t,ans;

    while(scanf("%d%d%d%d",&n,&m,&k,&l)!=EOF && n||m||k||l){
        memset(a,-1,sizeof(a));
        ans=0;
        while(l--){
            scanf("%d",&t);
            x=t%n;
            t/=n;
            y=t%m;
            t/=m;
            z=t;
            a[x+1][y+1][z+1]=1;
            ans+=6;
        }
        q[0].x=q[0].y=q[0].z=0;
        a[0][0][0]=0;
        p=0;t=1;
        while(p<t){
            for(l=0;l<6;l++){
                x=q[p].x+d[l][0];
                y=q[p].y+d[l][1];
                z=q[p].z+d[l][2];
                if(isacm(x,y,z)==-1){
                    q[t].x=x;
                    q[t].y=y;
                    q[t].z=z;
                    t++;
                    a[x][y][z]=0;
                }
            }
            p++;
        }
        for(x=1;x<=n;x++)
            for(y=1;y<=m;y++)
                for(z=1;z<=k;z++){
                    if(isacm(x,y,z)!=1) continue;
                    for(t=0;t<6;t++)
                        if(isacm(x+d[t][0],y+d[t][1],z+d[t][2])) ans--;
                }
        printf("The number of faces needing shielding is %d.\n",ans);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2677000 2007-11-15 17:55:36 Accepted 1063 C 00:00.20 3416K わたし

#include <stdio.h>
#include <string.h>
char a[62][62][62];
int n,m,k;
const int d[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int p,tt;
struct pos{
    int x,y,z;
}q[62*62*62];
int isacm(int x,int y,int z)
{
    if(x<0||y<0||z<0||x>n+1||y>m+1||z>k+1) return 0;
    else return a[x][y][z];
}
int main()
{
    int l,x,y,z,t,ans;

    while(scanf("%d%d%d%d",&n,&m,&k,&l)!=EOF && n||m||k||l){
        memset(a,-1,sizeof(a));
        ans=0;
        while(l--){
            scanf("%d",&t);
            x=t%n;
            t/=n;
            y=t%m;
            t/=m;
            z=t;
            a[x+1][y+1][z+1]=1;
        }
        q[0].x=q[0].y=q[0].z=0;
        a[0][0][0]=0;
        p=0;tt=1;
        while(p<tt){
            for(l=0;l<6;l++){
                x=q[p].x+d[l][0];
                y=q[p].y+d[l][1];
                z=q[p].z+d[l][2];
                t=isacm(x,y,z);
                if(t==-1){
                    q[tt].x=x;
                    q[tt].y=y;
                    q[tt].z=z;
                    tt++;
                    a[x][y][z]=0;
                }
                else if(t==1) ans++;
            }
            p++;
        }
        printf("The number of faces needing shielding is %d.\n",ans);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2676999 2007-11-15 17:55:06 Accepted 1063 C 00:00.18 3424K わたし

// 2012-09-07 13:34:48 | Accepted | 2326 | C++ | 0 | 188 | milkronus | Source
