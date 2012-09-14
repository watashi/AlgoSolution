/* //离散化 */
/* //?线段树（我不知道，以后再看） */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *pa,const void *pb)
{
    int a=*(int *)pa,b=*(int *)pb;

    return (a==b)?0:((a<b)?-1:1);
}
int mp[12021];
char se[12021];
struct input{
    int f,t;
    char c;
}in[2002];
int main()
{
    int i,j,k,n,m;
    int f,t,len;
    char color[4];

    while(scanf("%d",&n)!=EOF){
        t=0;
        for(k=0;k<n;k++){
            scanf("%d%d%s",&i,&j,color);
            in[k].f=i;
            in[k].t=j;
            in[k].c=*color;
            mp[t++]=i-1;mp[t++]=i;mp[t++]=i+1;/*-.-*/
            mp[t++]=j-1;mp[t++]=j;mp[t++]=j+1;/*-.-*/
        }
        qsort(mp,t,sizeof(int),cmp);
        i=j=0;
        while(i<t){
            mp[j]=mp[i++];
            while(i<t&&mp[i]==mp[j]) i++;
            j++;
        }
        m=j;
        memset(se,'b',sizeof(se));
        for(k=0;k<n;k++){
            i=(int *)bsearch(&in[k].f,mp,m,sizeof(int),cmp)-mp;
            j=(int *)bsearch(&in[k].t,mp,m,sizeof(int),cmp)-mp;
            while(i<=j) se[i++]=in[k].c;
        }
        len=0;
        for(k=0;k<m;k++){
            if(se[k]!='w') continue;
            i=mp[k];
            while(se[++k]=='w');
            --k;
            j=mp[k];
            if(j-i+1>len){/*T_T*/
                len=j-i+1;/*T_T*/
                f=i;
                t=j;
            }
        }
        if(len) printf("%d %d\n",f,t);
        else printf("Oh, my god\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2683413 2007-11-23 15:37:03 Accepted 2301 C 00:00.02 528K わたし */

// 2012-09-07 03:09:51 | Accepted | 2301 | C | 10 | 240 | watashi | Source
