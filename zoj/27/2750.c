#include <stdio.h>
#include <string.h>
#define INF 999999999
typedef struct{
int b,e,t;
}node;
node p[1000];
int mark[1000],d[1000];
int map[1000][1000];
void getit(int x)
{
    char str[1000];

    scanf("%d %s",&p[x].t,str);
    sscanf(str+strlen(str)-4,"%x",&p[x].e);
    str[4]='\0';
    sscanf(str,"%x",&p[x].b);
}
int main()
{
    int i,j,k,t,w,n;

    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            getit(i);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                if(p[i].e==p[j].b) map[i][j]=p[i].t;
                else map[i][j]=INF;
            }
        for(i=0;i<n;i++){
            mark[i]=0;
            d[i]=map[0][i];
        }
        d[0]=0;mark[0]=1;
        for(k=1;k<n;k++){
            w=INF;
            for(i=0;i<n;i++)
                if(mark[i]==0&&d[i]<w){w=d[i];t=i;}
            mark[t]=1;
            for(i=0;i<n;i++)
                if(mark[i]==0&&d[i]>d[t]+map[t][i]) d[i]=d[t]+map[t][i];
        }
        printf("%d\n",(d[n-1]<INF)?d[n-1]:-1);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2594326 2007-09-03 04:26:32 Accepted 2750 C 00:00.33 4324K ¤ï¤¿¤· */

// 2012-09-07 03:12:42 | Accepted | 2750 | C | 160 | 4084 | watashi | Source
