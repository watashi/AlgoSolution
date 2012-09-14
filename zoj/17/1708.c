#include <stdio.h>
int main()
{
    int grid[12][12]={{0,0,0,0,0,0,0,0,0,0,0,0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
    int i,j,r,c,x,y,count;
    char ch;

    while(scanf("%d%d%d",&r,&c,&y),r){
        getchar();
        for(i=1;i<=r;i++){
            for(j=1;j<=c+1;j++){
                ch=getchar();
                switch(ch){
                case 'N':grid[i][j]=-1;break;
                case 'S':grid[i][j]=-2;break;
                case 'W':grid[i][j]=-3;break;
                case 'E':grid[i][j]=-4;break;
                case '\n':grid[i][j]=0;break;
                }
            }
        }
        for(j=0;j<=c+1;j++)
            grid[r+1][j]=0;
        x=1;
        count=1;
        while(1){
            if(grid[x][y]>0){printf("%d step(s) before a loop of %d step(s)\n",grid[x][y]-1,count-grid[x][y]);break;}
            else if(grid[x][y]==0){printf("%d step(s) to exit\n",count-1);break;}
            else{
                switch(grid[x][y]){
                case -1:grid[x][y]=count;count++;x--;break;
                case -2:grid[x][y]=count;count++;x++;break;
                case -3:grid[x][y]=count;count++;y--;break;
                case -4:grid[x][y]=count;count++;y++;break;
                }
            }
        }
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2502470 2007-06-25 15:06:08 Accepted 1708 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 00:58:11 | Accepted | 1708 | C | 0 | 160 | watashi | Source
