#include <stdio.h>
#include <string.h>
int main()
{
    char cmd[10],url[101][70]={"http://www.acm.org/"};
    int i,n,ri,repeat;

    scanf("%d",&repeat);
    for(ri=0;ri<repeat;ri++){
        if(ri) printf("\n");
        i=0;
        n=1;
        while(scanf("%s",cmd)){
            if(!strcmp(cmd,"QUIT")) break;
            else if(!strcmp(cmd,"VISIT")){
                scanf("%s",url[++i]);
                n=i+1;
                puts(url[i]);
            }
            else if(!strcmp(cmd,"FORWARD")){
                if(i>=n-1) printf("Ignored\n");
                else puts(url[++i]);
            }
            else if(!strcmp(cmd,"BACK")){
                if(i) puts(url[--i]);
                else printf("Ignored\n");
            }
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2487385 2007-06-10 06:21:29 Accepted 1061 C 00:00.00 412K ¤ï¤¿¤· */

// 2012-09-07 02:55:18 | Accepted | 1061 | C | 0 | 160 | watashi | Source
