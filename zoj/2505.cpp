#include <cstring> // auto fix CE
#include <cstdio>
#include <string>
#define MAXN 4100
int main()
{
    int re,t,i,j,k,len;
    bool s[MAXN];

    scanf("%d",&re);
    while(re--){
        memset(s,0,sizeof(s));
        scanf("%d",&t);
        len=0;
        while(t--){
            scanf("%d",&k);
            if(s[k]) s[k]=false;
            else{
                s[k]=true;
                for(i=k-1;s[i];i--);
                for(j=k+1;s[j];j++);
                if(j-i-1>len) len=j-i-1;
            }
        }
        printf("%d\n",len);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2627812 2007-10-01 21:56:05 Accepted 2505 C++ 00:00.09 388K ¤ï¤¿¤·

// 2012-09-07 13:36:10 | Accepted | 2505 | C++ | 30 | 180 | watashi | Source
