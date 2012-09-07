/*
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <string.h>
int main()
{
    char ch[2000002],str[4000002];
    long t,l;

    while(scanf("%s",ch),ch[1]||ch[0]!='.'){
        l=strlen(ch);
        strcpy(str,ch);
        strcat(str+l,ch);
        t=strstr(str+1,ch)-str;
        printf("%d\n",l/t);
    }
}
//TLE
*/
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <string.h>
int main()
{
    char ch[2000002];
    long i,j,l;

    while(scanf("%s",ch),ch[1]||ch[0]!='.'){
        l=strlen(ch);
        for(i=1;i<l;i++)
            if(l%i==0){
                for(j=0;ch[i+j]==ch[j];j++);
                if(!ch[i+j]) break;
            }
        printf("%ld\n",l/i);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2501797 2007-06-24 14:07:08 Accepted 1905 C 00:00.50 2344K ¤ï¤¿¤·
//so dramatically different!!

// 2012-09-07 14:09:30 | Accepted | 1905 | C++ | 100 | 180 | watashi | Source
