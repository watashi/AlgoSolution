#include <stdio.h>
#include <string.h>
int main()
{
    char code[10][12];
    int i,j,not,ri=0;

    while(gets(code[i=0])){
        not=0;
        while(gets(code[++i]),code[i][0]!='9'){
            for(j=0;j<i&&!not;j++)
                if(strstr(code[i],code[j])==code[i]||strstr(code[j],code[i])==code[j]) not=1;
        }
        if(not) printf("Set %d is not immediately decodable\n",++ri);
        else printf("Set %d is immediately decodable\n",++ri);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2485934 2007-06-09 01:51:01 Accepted 1808 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 01:01:33 | Accepted | 1808 | C | 0 | 160 | watashi | Source
