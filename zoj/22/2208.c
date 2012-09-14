#include <stdio.h>
int main()
{
    char ch[100][20];
    int i,j,m,n;

    while(scanf("%d\n",&n),n){
        for(i=0;;i++){
            if(i%2==0)
            for(j=0;j<n;j++){
                scanf("%c",&ch[i][j]);
                if(ch[i][j]=='\n'){
                    m=-1;
                    break;
                }
            }
            else
            for(j=1;j<=n;j++){
                scanf("%c",&ch[i][n-j]);
                if(ch[i][n-j]=='\n'){
                    m=-1;
                    break;
                }
            }
            if(m==-1) break;
        }
        m=i;
        for(j=0;j<n;j++)
            for(i=0;i<m;i++)
                printf("%c",ch[i][j]);
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2463933 2007-05-26 16:06:04 Accepted 2208 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 01:16:01 | Accepted | 2208 | C | 0 | 160 | watashi | Source
