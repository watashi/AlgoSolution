/* //正则表达式为 ^([\\+\\-])?(?<integral_digits>\\d*)?((\\.)(?<fractional_digits>\\d*))?(([eE])(?<exponent>[\\+\\-]?\\d+))?$ */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
int isFloat(const char p[])
{
    int i,j;

    i=0;
    if(p[i]=='+'||p[i]=='-') i++;
    j=i;
    while(isdigit(p[j])) j++;
    if(i==j){
        if(p[i]!='.') return 0;
        else j=++i;
        while(isdigit(p[j])) j++;
        if(i==j) return 0;
        else i=j;
    }
    else{
        i=j;
        if(p[i]=='.') i++;
        while(isdigit(p[i])) i++;
    }
    if(p[i]=='e'||p[i]=='E'){
        i++;
        if(p[i]=='+'||p[i]=='-') i++;
        j=i;
        while(isdigit(p[j])) j++;
        if(i==j) return 0;
        else i=j;
    }
    if(p[i]=='\0') return 1;
    else return 0;
}
int main()
{
    char str[1024];

    while(gets(str)!=NULL && strcmp(str,"#"))/*/空行/*/
        printf("%s\n",isFloat(str)?"Yes":"No");
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2674321 2007-11-13 15:41:45 Accepted 2622 C 00:00.00 392K わたし */

// 2012-09-07 01:32:36 | Accepted | 2622 | C | 0 | 160 | watashi | Source
