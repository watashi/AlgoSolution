/*1709 Oil Deposits.c*/
#include <stdio.h>
char a[22][22];
int count;
void kill(int i,int j)
{
    count++;
    a[i][j]='#';
    if(a[i-1][j]=='.') kill(i-1,j);
    if(a[i][j-1]=='.') kill(i,j-1);
    if(a[i][j+1]=='.') kill(i,j+1);
    if(a[i+1][j]=='.') kill(i+1,j);
}
int main()
{
    int i,j,x,y;

    for(i=0;i<22;i++)
        a[0][i]=a[i][0]='#';
    while(scanf("%d%d",&y,&x),x){
    count=0;
    for(i=1;i<=x;i++)
        scanf("%s",&a[i][1]);
    for(j=0;j<=y+1;j++)
        a[x+1][j]='#';
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            if(a[i][j]=='@'){
                kill(i,j);
            }
        }
    }
    printf("%d\n",count);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2488092 2007-06-10 23:05:26 Accepted 2165 C 00:00.00 404K ¤ï¤¿¤· */

// 2012-09-07 03:08:56 | Accepted | 2165 | C | 0 | 160 | watashi | Source
