/*
#include <stdio.h>
int main()
{
    char ch;
    int i,j,k,n,map[100][100],ans;

    while(scanf("%d ",&n)!=EOF){
        ans=0;
        for(i=0;i<n;i++){
            ch=getchar();
            if(ch=='.'){map[i][0]=1;ans++;}
            else map[i][0]=0;
            for(j=1;j<n;j++){
                ch=getchar();
                if(ch=='.') ans+=(map[i][j]=map[i][j-1]+1);
                else map[i][j]=0;
            }
            getchar();
        }
        for(k=n-1;k;k--)
            for(i=0;i<k;i++)
                for(j=0;j<n;j++){
                    if(map[i][j]>map[i+1][j]) map[i][j]=map[i+1][j];
                    ans+=map[i][j];
                }
        printf("%d\n",ans);
    }
}
*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2578696 2007-08-21 22:58:22 Accepted 2067 C 00:00.14 428K わたし */
#include <stdio.h>
int main()
{
    char ch;
    int i,j,k,n,m,map[100][100],ans;

    while(scanf("%d ",&n)!=EOF){
        ans=0;
        for(i=0;i<n;i++){
            ch=getchar();
            if(ch=='.') map[i][0]=1;
            else map[i][0]=0;
            for(j=1;j<n;j++){
                ch=getchar();
                if(ch=='.') map[i][j]=map[i][j-1]+1;
                else map[i][j]=0;
            }
            getchar();
        }
        ans=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(m=map[i][j]){
                    ans+=m;
                    for(k=i+1;m!=0&&k<n;k++){
                        if(m>map[k][j]) m=map[k][j];
                        ans+=m;
                    }
                }
        printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2578709 2007-08-21 23:11:58 Accepted 2067 C 00:00.09 432K わたし */

// 2012-09-07 03:08:01 | Accepted | 2067 | C | 30 | 160 | watashi | Source
