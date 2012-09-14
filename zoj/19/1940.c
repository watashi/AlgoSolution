#include <stdio.h>
char mp[33][33][33];
int mind[33][33][33];
int d[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int q[27000][3];
int x,y,z;
int islegal(int i,int j,int k)
{
    return i>=0&&i<x&&j>=0&&j<y&&k>=0&&k<z;
}
int main()
{
    int i,j,k;
    int t,p,tail;

    while(scanf("%d%d%d ",&x,&y,&z)!=EOF && x||y||z){
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                for(k=0;k<z;k++){
                    mind[i][j][k]=-1;
                    mp[i][j][k]=getchar();
                    if(mp[i][j][k]=='S'){q[0][0]=i;q[0][1]=j;q[0][2]=k;mind[i][j][k]=0;}
                }
                getchar();
            }
            getchar();
        }
        p=0;
        tail=1;
        while(p<tail){
            if(mp[q[p][0]][q[p][1]][q[p][2]]=='E') break;
            for(t=0;t<6;t++){
                i=q[p][0]+d[t][0];
                j=q[p][1]+d[t][1];
                k=q[p][2]+d[t][2];
                if(islegal(i,j,k)&&mind[i][j][k]==-1&&mp[i][j][k]!='#'){
                    mind[i][j][k]=mind[q[p][0]][q[p][1]][q[p][2]]+1;
                    q[tail][0]=i;q[tail][1]=j;q[tail][2]=k;
                    tail++;
                }
            }
            p++;
        }
        if(p==tail) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",mind[q[p][0]][q[p][1]][q[p][2]]);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2650243 2007-10-19 13:59:48 Accepted 1940 C 00:00.02 888K ¤ï¤¿¤· */

// 2012-09-07 03:07:13 | Accepted | 1940 | C | 0 | 652 | watashi | Source
