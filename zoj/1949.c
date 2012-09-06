#include <stdio.h>
int main()
{
    int i,j,gg,n,r,c,a[101][101];
    long sum;/**/

    while(scanf("%d",&n),n){
        gg=0;
        r=-1;
        for(i=0;i<n;i++){
            sum=0;
            for(j=0;j<n;j++){
                scanf("%d",&a[i][j]);
                sum+=a[i][j];
            }
            if(sum%2&&r>=0){
                gg=1;/*NO BREAK*/
            }
            else if(sum%2) r=i;
        }
        c=-1;
        if(!gg)
            for(j=0;j<n;j++){
                sum=0;
                for(i=0;i<n;i++)
                    sum+=a[i][j];
                if(sum%2&&c>=0){
                    gg=1;
                    break;
                }
                else if(sum%2) c=j;
            }
        if(gg) printf("Corrupt\n");
        else if(r>=0&&c>=0) printf("Change bit (%d,%d)\n",r+1,c+1);
        else if(r+c==-2) printf("OK\n");
        else printf("Corrupt\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2470052 2007-05-29 16:48:36 Accepted 1949 C 00:00.01 428K ¤ï¤¿¤· */

// 2012-09-07 01:07:54 | Accepted | 1949 | C | 10 | 160 | watashi | Source
