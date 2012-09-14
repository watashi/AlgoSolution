#include <stdio.h>
char* slump(char *p)
{
    if(*p!='D'&&*p!='E') return NULL;
    if(*++p!='F') return NULL;
    while(*++p=='F');
    if(*p=='G') return ++p;
    else return slump(p);
}
char* slimp(char *p)
{
    if(*p!='A') return NULL;
    switch(*++p){
    case 'B':
        p=slimp(++p);
        if(p&&*p=='C') return ++p;
        else return NULL;
    case 'H':
        return ++p;
    default:
        p=slump(p);
        if(p&&*p=='C') return ++p;
        else return NULL;
    }
}
int main()
{
    int re;
    char str[66],*p;

    printf("SLURPYS OUTPUT\n");
    scanf("%d",&re);
    while(re--){
        scanf("%s",str);
        if((p=slimp(str)) && (p=slump(p)) && *p=='\0') printf("YES\n");
        else printf("NO\n");
    }
    printf("END OF OUTPUT\n");

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2656621 2007-10-24 14:31:55 Accepted 1286 C 00:00.00 384K ¤ï¤¿¤· */

// 2012-09-07 02:58:47 | Accepted | 1286 | C | 0 | 160 | watashi | Source
