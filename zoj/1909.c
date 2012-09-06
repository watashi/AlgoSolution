#include <stdio.h>
int i,j,k;
int n,a[20],sum;
int mark[20];
int dfs(int remind,int rest,int begin)
{
    int i;

    if(remind==0) return 1;
    else if(rest==0) return dfs(remind-1,sum,1);
    else if(rest==sum){
        for(i=0;mark[i];i++);
        mark[i]=1;
        if(dfs(remind,sum-a[i],i+1)) return 1;
        else{mark[i]=0;return 0;}
    }
    else{
        for(i=begin;i<n;i++)
            if(!mark[i] && a[i]<=rest){
                mark[i]=1;
                if(dfs(remind,rest-a[i],i+1)) return 1;
                mark[i]=0;
            }
        return 0;
    }
}
int main()
{
    int re;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++){
            mark[i]=0;
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%4){
            printf("no\n");
            continue;
        }
        else sum/=4;
        for(i=0;i<n;i++){
            k=i;
            for(j=i+1;j<n;j++)
                if(a[j]>a[k]) k=j;
            j=a[i];a[i]=a[k];a[k]=j;
        }
        if(a[0]<=sum && dfs(3,sum,1)) printf("yes\n");
        else printf("no\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2632427 2007-10-05 01:43:47 Accepted 1909 C 00:00.00 388K わたし */

/*
Rank Submit time Run time Run memory Language User
1 2006-05-05 12:21:58 00:00.00 388K C CrazyBird
2 2006-05-18 14:16:19 00:00.00 388K C mj
3 2006-08-05 15:10:13 00:00.00 388K C Sorry
4 2007-10-05 01:43:47 00:00.00 388K C わたし
5 2007-08-11 10:21:46 00:00.00 392K C shanshui
6 2005-11-13 22:46:20 00:00.00 404K FPC 鷲州
7 2006-06-30 10:17:26 00:00.00 408K FPC jsy
*/

// 2012-09-07 01:05:49 | Accepted | 1909 | C | 0 | 160 | watashi | Source
