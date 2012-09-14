#include <stdio.h>
#include <string.h>
char mp[50][50];
int mind[50][50][50];
struct state{
    int x,y,z;
}q[50*50*50];
int main()
{
    int p,t;
    int i,n,x,y,z,ans;

    while(scanf("%d",&n)!=EOF && n){
        for(x=0;x<n;x++)
            for(y=0;y<n;y++)
                for(z=0;z<n;z++)
                    mind[x][y][z]=-1;
        scanf("%d%d%d ",&x,&y,&z);
        x--;y--;z--;
        mind[x][y][z]=0;
        q[0].x=x;q[0].y=y;q[0].z=z;
        for(x=0;x<n;x++)
            for(y=0;y<n;y++){
                do{
                    mp[x][y]=getchar();
                }while(mp[x][y]==' '||mp[x][y]=='\n');
            }
        p=0;t=1;
        while(p<t){
            x=q[p].x;
            y=q[p].y;
            z=q[p].z;
            for(i=0;i<n;i++){
                if(mind[i][y][z]==-1&&mp[x][i]==mp[y][z]){
                    mind[i][y][z]=mind[x][y][z]+1;
                    q[t].x=i;q[t].y=y;q[t].z=z;t++;
                }
                if(mind[x][i][z]==-1&&mp[y][i]==mp[x][z]){
                    mind[x][i][z]=mind[x][y][z]+1;
                    q[t].x=x;q[t].y=i;q[t].z=z;t++;
                }
                if(mind[x][y][i]==-1&&mp[z][i]==mp[x][y]){
                    mind[x][y][i]=mind[x][y][z]+1;
                    q[t].x=x;q[t].y=y;q[t].z=i;t++;
                }
            }
            p++;
        }
        ans=-1;
        for(i=0;i<n;i++)
            if(mind[i][i][i]!=-1&&(ans==-1||mind[i][i][i]<ans)) ans=mind[i][i][i];
        if(ans==-1) printf("impossible\n");
        else printf("%d\n",ans);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2677113 2007-11-15 20:21:14 Accepted 1103 C 00:00.89 2352K わたし

//数据有问题，部分尾部多空格

// 2012-09-07 00:36:57 | Accepted | 1103 | C++ | 380 | 2136 | watashi | Source
