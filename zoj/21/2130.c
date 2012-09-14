#include <stdio.h>
int i,j,ii,jj,H,W,h,w;
char MP[61][61],mp[61][61];
int main()
{
    int ans;

    while(scanf("%d%d%d%d",&H,&W,&h,&w)!=EOF){
        ans=0;
        for(i=0;i<H;i++)
            scanf("%s",MP[i]);
        for(ii=0;ii<h;ii++)
            scanf("%s",mp[ii]);
        for(i=0;i+h<=H;i++)
            for(j=0;j+w<=W;j++){
                for(ii=0;ii<h;ii++){
                    for(jj=0;jj<w;jj++)
                        if(!(mp[ii][jj]=='.'||mp[ii][jj]==MP[i+ii][j+jj])) break;
                    if(jj<w) break;
                }
                if(ii==h) ans++;
            }
        printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2652751 2007-10-21 09:45:39 Accepted 2130 C 00:00.09 396K ¤ï¤¿¤· */

// 2012-09-07 03:08:32 | Accepted | 2130 | C | 30 | 168 | watashi | Source
