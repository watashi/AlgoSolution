#include <stdio.h>
#include <string.h>
int bin[20];
int rule[2][2][2];
int mind[1<<16];
int getbit(int x,int i)
{
    if(x&bin[i]) return 1;
    else return 0;
}
int shift(int x,int n)
{
    int res=(x>>1);

    if(x&1) res|=bin[n-1];
    return res;
}
int rewrite(int x,int n)
{
    int i;
    int res=0;

    for(i=n-1;i>=0;i--)
        if(rule[getbit(x,(i+2)%n)][getbit(x,i)][getbit(x,(i-1+n)%n)]) res|=bin[i];
    return res;
}
int main()
{
    char str[20];
    int i,k,n,s,t;

    for(i=0;i<20;i++)
        bin[i]=(1<<i);
    while(scanf("%d",&n)!=EOF){
        memset(mind,0xff,sizeof(mind));
        scanf("%s",str);
        t=0;
        for(i=0;i<n;i++){
            t<<=1;
            if(str[i]=='b') t++;
        }
        mind[t]=0;
        for(i=0;i<8;i++){
            scanf("%s",str);
            rule[str[0]-'a'][str[1]-'a'][str[2]-'a']=str[3]-'a';
        }
        scanf("%d",&s);
        for(i=1;i<=s;i++){
            t=rewrite(t,n);
            if(mind[t]==-1) mind[t]=i;
            else break;
        }
        if(i<s){
            k=(s-mind[t])%(i-mind[t])+mind[t];
            i=0;
            while(mind[i]!=k) i++;
            t=i;
        }
        k=t;
        for(i=1;i<n;i++){
            t=shift(t,n);
            if(t<k) k=t;
        }
        for(i=n-1;i>=0;i--)
            putchar('a'+getbit(k,i));
        putchar('\n');
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2655974 2007-10-23 21:24:00 Accepted 1262 C 00:00.09 648K ¤ï¤¿¤· */

// 2012-09-07 02:58:23 | Accepted | 1262 | C | 40 | 416 | watashi | Source
