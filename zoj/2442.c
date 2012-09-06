#include <stdio.h>
#include <string.h>
char str[2][256];
int prelen(char pre[],char str[])
{
    int i,j;
    for(i=0;pre[i]&&pre[i]==str[i];i++);
    for(j=i;str[j];j++);
    return j-i+1;
}
int main()
{
    int re;
    int i,n,p,ans;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        scanf("%s",str[p=0]);
        ans=strlen(str[p]);
        for(i=1;i<n;i++){
            p=!p;
            scanf("%s",str[p]);
            ans+=prelen(str[!p],str[p]);
        }
        printf("%d\n",ans);
        if(re) putchar('\n');
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684046 2007-11-24 11:23:18 Accepted 2442 C 00:00.20 388K ¤ï¤¿¤· */

// 2012-09-07 01:23:36 | Accepted | 2442 | C | 30 | 160 | watashi | Source
