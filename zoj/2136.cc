#include <cstdio> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    int re,i,j,n,a[1000],dp[1000],max;

    scanf("%d",&re);
    while(re--){
        max=1;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            dp[i]=1;
            for(j=0;j<i;j++){
                if(a[j]<a[i]&&dp[j]+1>dp[i]) dp[i]=dp[j]+1;
            }
            if(dp[i]>max) max=dp[i];
        }
        printf("%d\n",max);
        if(re) printf("\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2530247 2007-07-22 19:56:45 Accepted 2136 C 00:00.01 396K ¤ï¤¿¤·
/*************************LIS.C******************************/
//int longest_inc_sequence(int x[], int n)
//{
//     int  *last;              /* the last of a n-seubseq. */
//     int  length;             /* current max inc. subseq. */
//     int  left;               /* left bound for bin search*/
//     int  right;              /* right bound              */
//     int  mid;                /* the middle point.        */
//     int  i;
//
//     last = (int *) malloc(sizeof(int)*n); /* get work mem*/
//
//     last[0] = x[0];          /* start from the beginning */
//     length  = 0;             /* len=1 and x[0] in subseq */
//     for (i = 1; i < n; i++)  /* scan all other items     */
//          if (x[i] >= last[length]) /* higher than max?   */
//               last[++length] = x[i]; /* YES, record it.  */
//          else if (x[i] < last[0]) /* NO, less then 1st   */
//               last[0] = x[i]; /* it would be the new head*/
//          else {              /* now insert it with bin.sr*/
//              for (left = 0, right = length; left != right-1; ) {
//                    mid = (left + right) / 2;
//                    (last[mid] <= x[i]) ? (left = mid) : (right = mid);
//               }
//               last[right] = x[i];
//          }
//     free(last);              /* finally release memory   */
//     return length + 1;       /* return the true length   */
//}
/*************************LIS.C******************************/

// 2012-09-07 14:10:03 | Accepted | 2136 | C++ | 0 | 180 | watashi | Source
