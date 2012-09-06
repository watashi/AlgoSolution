#include <stdio.h>
int main()
{
    int ri,repeat,i;
    char url[61];

    scanf("%d\n",&repeat);
    for(ri=1;ri<=repeat;ri++){
        gets(url);
        printf("URL #%d\n",ri);
        i=0;
        printf("Protocol = ");
        while(url[i]!=':')
            printf("%c",url[i++]);
        printf("\n");
        i+=3;
        printf("Host     = ");
        while(url[i]!=':'&&url[i]!='/'&&url[i]!='\0')
            printf("%c",url[i++]);
        printf("\n");
        printf("Port     = ");
        if(url[i]=='\0'){
            printf("<default>\nPath     = <default>\n");

        }
        else if(url[i]=='/'){
            printf("<default>\n");
            printf("Path     = ");
            puts(url+i+1);
        }
        else{
            while(url[++i]!='/'&&url[i]!='\0')
                printf("%c",url[i]);
            printf("\n");
            printf("Path     = ");
            if(url[i]=='\0')
                printf("<default>\n");
            else
                puts(url+i+1);
        }
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2471773 2007-05-30 15:10:01 Accepted 1243 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 02:58:17 | Accepted | 1243 | C | 0 | 160 | watashi | Source
