#include <stdio.h>
#include <string.h>
int main()
{
    char c,t[12],a[12][12]={{"..........."},{'.'},{'.'},{'.'},{'.'},{'.'},{'.'},{'.'},{'.'},{'.'},{'.'}};
    int n,i,j,flag,begin=0;

    while(scanf("%d",&n)!=EOF){
        if(begin) putchar('\n');
        else begin=1;
        for(i=1;i<=n;i++)
            scanf("%s",&a[i][1]);
        strcpy(a[n+1],"...........");
        flag=0;
        for(i=1;i<=n;i++){
            scanf("%s",t+1);
            for(j=1;j<=n;j++){
                if(t[j]=='x'){
                    if(a[i][j]=='*') flag=1;
                    else{
                        a[i][j]=0;
                        if(a[i-1][j-1]=='*')    a[i][j]++;
                        if(a[i-1][j]=='*')      a[i][j]++;
                        if(a[i-1][j+1]=='*')    a[i][j]++;
                        if(a[i][j-1]=='*')      a[i][j]++;
                        if(a[i][j+1]=='*')      a[i][j]++;
                        if(a[i+1][j-1]=='*')    a[i][j]++;
                        if(a[i+1][j]=='*')      a[i][j]++;
                        if(a[i+1][j+1]=='*')    a[i][j]++;
                    }
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(a[i][j]=='.') putchar('.');
                else if(a[i][j]=='*'){
                    if(flag) putchar('*');
                    else putchar('.');
                }
                else putchar(a[i][j]+'0');
            }
            putchar('\n');
        }
    }

    return 0;   /* NZEC */
}

/* //Presentation Error */
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2512056 2007-07-08 23:11:45 Accepted 1862 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:05:50 | Accepted | 1862 | C | 0 | 160 | watashi | Source
