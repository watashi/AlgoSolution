/* //LIS.C//dp */
#include <stdio.h>
int main()
{
    long re,i,n,t,l,r,mid,len,last[40000];

    scanf("%ld",&re);
    while(re--){
        scanf("%ld",&n);
        scanf("%ld",&last[0]);
        len=0;
        for(i=1;i<n;i++){
            scanf("%ld",&t);
            if(t>=last[len]){
                last[++len]=t;
            }
            else if(t<last[0]){
                last[0]=t;
            }
            else{
                /*******/
                l=0;r=len;
                while(l!=r-1){
                    mid=(l+r)/2;
                    if(last[mid]<=t) l=mid;
                    else r=mid;
                }
                last[r]=t;
                /*******/
            }
        }
        printf("%ld\n",len+1);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2530287 2007-07-22 20:24:31 Accepted 1986 C 00:00.14 552K ¤ï¤¿¤· */

// 2012-09-07 01:09:38 | Accepted | 1986 | C | 60 | 160 | watashi | Source
