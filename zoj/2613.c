#include <stdio.h>
#include <string.h>
struct record{
    int cc;
    char c[21];
}rec[10001];
int main()
{
    int ri,re,i,j,n,m;

    for(scanf("%d",&re),ri=1;ri<=re;ri++){
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++)
            rec[i].cc=0;
        while(m--){
            scanf("%s%d",rec[0].c,&j);
            if(!rec[j].cc) strcpy(rec[j].c,rec[0].c);
            rec[j].cc++;
        }
        j=0;
        for(i=1;i<=n;i++)
            if(rec[i].cc&&(!j||rec[i].cc<rec[j].cc)) j=i;
        printf("Case %d:\nThe winner is %s.\nThe price is %d.\n",ri,rec[j].c,j);
        if(ri<re) putchar('\n');
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2674938 2007-11-13 21:37:45 Accepted 2613 C 00:00.11 668K ¤ï¤¿¤· */

// 2012-09-07 03:11:53 | Accepted | 2613 | C | 30 | 432 | watashi | Source
