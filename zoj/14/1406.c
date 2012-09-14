#include <stdio.h>
#define INF 999999999
int main()
{
    char ch[5];
    int i,j,n,p,t,d,min,sum,mark[26],map[26][26];

    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            mark[i]=map[i][i]=0;
            for(j=i+1;j<n;j++)
                map[i][j]=map[j][i]=INF;
        }
        for(i=1;i<n;i++){
            scanf("%s%d",ch,&p);
            t=ch[0]-'A';
            while(p--){
                scanf("%s%d",ch,&d);
                map[t][ch[0]-'A']=map[ch[0]-'A'][t]=d;
            }
        }
        p=mark[0]=1;
        sum=0;
        while(p<n){
            t=-1;
            min=INF;
            for(i=0;i<n;i++){
                if(mark[i]==0) continue;
                for(j=0;j<n;j++){
                    if(mark[j]) continue;
                    if(map[i][j]<min){min=map[i][j];t=j;}
                }
            }
            mark[t]=1;
            p++;
            sum+=min;
        }
        printf("%d\n",sum);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2549800 2007-08-02 17:28:05 Accepted 1406 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 00:48:38 | Accepted | 1406 | C | 0 | 160 | watashi | Source
