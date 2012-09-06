#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,n,m,t;
    char *p,str[128];

    while(scanf("%d ",&n)!=EOF && n){
        t=26;
        m=0;
        for(i=0;i<n;i++){
            gets(str);
            p=strchr(str,' ');
            if(p==NULL) j=0;
            else for(j=0;*p++==' ';j++);
            m+=j;
            if(j<t) t=j;
        }
        printf("%d\n",m-n*t);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2630985 2007-10-04 00:57:06 Accepted 1339 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 00:46:30 | Accepted | 1339 | C | 0 | 160 | watashi | Source
