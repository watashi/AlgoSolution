#include <cstring> // auto fix CE
#include <stdio.h>
#include <cstring> // auto fix CE
#include <stdlib.h>
#include <cstring> // auto fix CE
#include <string.h>
char mark[1771561];
char str[10];

int str2int()
{
    int i=0,res=0;

    while(str[i]){
        res*=11;
        res+=str[i++]-'/';
    };
    return res;
}
int doit()
{
    char swp;
    int i,j,tmp;

    if(mark[tmp=str2int()]!=-1) return mark[tmp];
    if(str[i=0]=='0') return mark[tmp]=1;
    while(swp=str[i]){
        if(swp=='0'){
            str[i]='\0';
            if(!doit()){str[i]=swp;/***/return mark[tmp]=1;}/**/
        }
        else{
            for(j=swp-1;j>='0';j--){
                str[i]=j;
                if(!doit()){str[i]=swp;/***/return mark[tmp]=1;}/**/
            }
        }
        str[i++]=swp;
    }
    return mark[tmp]=0;
}
int main()
{
    int i,j;

    memset(mark,0xff,sizeof(mark));
    while(scanf("%s",str)!=EOF)
        printf("%s\n",doit()?"Yes":"No");
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2674426 2007-11-13 16:40:40 Accepted 2725 C 00:00.66 2128K ¤ï¤¿¤·


/*
//·ÇµÝ¹é´ò±í

#include <cstring> // auto fix CE
#include <cstdio>
#include <cstring> // auto fix CE
#include <cstdlib>
using namespace std;

int a[1000000] = { 0 };

int main()
{

    for (int i=1; i<1000000; i++) {
        if (a[i])
            continue;
        int n = i;
        int j = 1;
        while (n) {
            int tmp = n % 10;
            n /= 10;
            for (int k=1; k<10-tmp; k++)
                a[i+k*j] = 1;
            j *= 10;
        }
        if (j < 1000000) {
            n = i * 10;
            a[n] = 1;
            int m = n + 1;
            while (n < 100000) {
                n *= 10;
                int tmp = n;
                m *= 10;
                while (tmp < m)
                    a[tmp++] = 1;
            }
        }
    }

    char str[7];

    while (scanf("%s", str) != EOF) {
        if (str[0] == '0')
            printf("Yes\n");
        else {
            int n = atoi(str);
            if (a[n])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}

//2307244 2007-03-28 16:14:50 Accepted 2725 C++ 00:00.10 4292K xgy
*/

// 2012-09-07 14:10:52 | Accepted | 2725 | C++ | 260 | 1908 | watashi | Source
