#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
double getf(char *p)
{
    double res;

    res=atof(p);
    while(!isalpha(*p)) p++;
    switch(*p){
    case 'm':res/=1000;break;
    case 'k':res*=1000;break;
    case 'M':res*=1000000;break;
    }
    return res;
}
int main()
{
    char text[1024],*c;
    int ri,re,x;
    double p,i,u;

    scanf("%d ",&re);
    for(ri=1;ri<=re;ri++){
        x=3;
        gets(text);
        if(c=strstr(text,"P=")){x-=0;c+=2;p=getf(c);}
        if(c=strstr(text,"I=")){x-=1;c+=2;i=getf(c);}
        if(c=strstr(text,"U=")){x-=2;c+=2;u=getf(c);}
        printf("Problem #%d\n",ri);
        switch(x){
        case 0:p=u*i;printf("P=%.2lfW\n",p);break;
        case 1:i=p/u;printf("I=%.2lfA\n",i);break;
        case 2:u=p/i;printf("U=%.2lfV\n",u);break;
        }
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2599118 2007-09-06 23:47:20 Accepted 1945 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:07:25 | Accepted | 1945 | C | 0 | 160 | watashi | Source
