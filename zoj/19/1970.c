#include <stdio.h>
#include <string.h>
int main()
{
    long i,l;
    char c,ch[100001];

    while(scanf("%s",ch)!=EOF){
        l=strlen(ch);
        i=0;
        while((c=getchar())!='\n'){
            if(c==ch[i]) i++;
        }
        if(i<l) printf("No\n");
        else printf("Yes\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2506101 2007-06-29 23:38:09 Accepted 1970 C 00:00.00 488K ¤ï¤¿¤· */

// 2012-09-07 03:07:37 | Accepted | 1970 | C | 0 | 160 | watashi | Source
