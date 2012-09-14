/* //!!!!!!!!!!!@@@@@@@@@@@@@@_____But, a player does not win the game if more than five stones of the same color were put consecutively. */



#include <stdio.h>
int main()
{
    int re,i,j,k,t,map[20][20];

    scanf("%d",&re);
    while(re--){
        for(i=1;i<=19;i++)
            for(j=1;j<=19;j++)
                scanf("%d",&map[i][j]);
        t=0;
        for(j=1;j<=19;j++){
            for(i=1;i<=19;i++){
                if(map[i][j]==0) continue;
                if(i<=15&&(i==1||map[i-1][j]!=map[i][j])){
                    for(k=1;k<5&&map[i+k][j]==map[i][j];k++);
                    if(k==5&&(i+k>19||map[i+k][j]!=map[i][j])){
                        t=map[i][j];
                        break;
                    }
                }
                if(j<=15){
                    if(j==1||map[i][j-1]!=map[i][j]){
                        for(k=1;k<5&&map[i][j+k]==map[i][j];k++);
                        if(k==5&&(j+k>19||map[i][j+k]!=map[i][j])){
                            t=map[i][j];
                            break;
                        }
                    }
                    if(i>=5&&(i==19||j==1||map[i+1][j-1]!=map[i][j])){
                        for(k=1;k<5&&map[i-k][j+k]==map[i][j];k++);
                        if(k==5&&(i-k==0||j+k>19||map[i-k][j+k]!=map[i][j])){
                            t=map[i][j];
                            break;
                        }
                    }
                    if(i<=15&&(i==1||j==1||map[i-1][j-1]!=map[i][j])){
                        for(k=1;k<5&&map[i+k][j+k]==map[i][j];k++);
                        if(k==5&&(i+k>19||j+k>19||map[i+k][j+k]!=map[i][j])){
                            t=map[i][j];
                            break;
                        }
                    }
                }
            }
            if(i<=19) break;
        }
        printf("%d\n",t);
        if(t) printf("%d %d\n",i,j);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2627921 2007-10-02 00:05:04 Accepted 2495 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 01:24:55 | Accepted | 2495 | C | 0 | 160 | watashi | Source
