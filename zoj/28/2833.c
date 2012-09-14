#include <stdio.h>
#include <string.h>
int a[100001];
int c[100001];
int run(int i)
{
    if(a[i]==i) return i;
    else return a[i]=run(a[i]);
}
void setFriend(int i,int j)
{
    i=run(i);
    j=run(j);
    if(i==j) return;
    else{
        a[j]=i;
        c[i]+=c[j];
    }
}
void query(int i)
{
    printf("%d\n",c[run(i)]);
}
int main()
{
    int ri=0,i,j,n,m;
    char cmd[5];

    while(scanf("%d%d",&n,&m)!=EOF){
        if(ri) putchar('\n');
        for(i=1;i<=n;i++){
            a[i]=i;
            c[i]=1;
        }
        printf("Case %d:\n",++ri);
        while(m--){
            scanf("%s",cmd);
            if(*cmd=='M'){
                scanf("%d%d",&i,&j);
                setFriend(i,j);
            }
            else{
                scanf("%d",&i);
                query(i);
            }
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2680938 2007-11-20 14:24:57 Accepted 2833 C 00:00.94 1180K ¤ï¤¿¤· */

// 2012-09-07 03:13:31 | Accepted | 2833 | C | 290 | 940 | watashi | Source
