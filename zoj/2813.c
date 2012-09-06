#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,l;
    char ch[88]="o";
    double p;

    while(scanf("%s",ch+1),strcmp(ch+1,"#")){
        l=strlen(ch+1);
        p=0;
        for(i=1;i<=l;i++){
            switch(ch[i]){
            case '.':break;
            case '_':p+=100.0/l;break;
            case '/':
                j=i;while(ch[--j]=='_');
                switch(ch[j]){
                case 'o':case '.':break;
                case '|':case '\\':p+=100.0/l;break;
                }
                break;
            case '\\':
                j=i;while(ch[++j]=='_');
                switch(ch[j]){
                case '\0':case '.':break;
                case '|':case '/':p+=100.0/l;break;
                }
                break;
            case '|':
                j=i;while(ch[--j]=='_');
                switch(ch[j]){
                case 'o':case '.':break;
                case '|':case '\\':p+=50.0/l;break;
                }
                j=i;while(ch[++j]=='_');
                switch(ch[j]){
                case '\0':case '.':break;
                case '|':case '/':p+=50.0/l;break;
                }
                break;
            }
        }
        printf("%d\n",(int)(100-p));
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2503935 2007-06-27 00:50:23 Accepted 2813 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 01:40:57 | Accepted | 2813 | C | 0 | 160 | watashi | Source
