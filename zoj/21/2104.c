#include <stdio.h>
#include <string.h>
struct balloon{
    char ch[16];
    int count;
}color[44];
int main()
{
    int i,j,ri,n,max,index;

    while(scanf("%d\n",&n),n){
        i=1;
        for(ri=1;ri<=n;ri++){
            gets(color[i].ch);
            color[i].count=0;
            for(j=1;j<i;j++)
                if(strcpy(color[i].ch,color[j].ch)) i++;
                else color[j].count++;
        }
        max=0;
        for(j=1;j<i;j++)
            if(color[j].count>max){
                index=j;
                max=color[j].count;
            }
        puts(color[j].ch);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2463857 2007-05-26 15:24:33 Accepted 2104 C 00:00.00 384K ¤ï¤¿¤· */

// 2012-09-07 03:08:20 | Accepted | 2104 | C | 0 | 160 | watashi | Source
