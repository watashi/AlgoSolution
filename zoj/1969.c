#include <stdio.h>
#include <string.h>
int main()
{
    char ch[80],str[80];
    long a,b,c,i,l;

    while(scanf("%s",ch)!=EOF){
        l=strlen(ch);
        for(i=0;i<l;i++)
            str[i]=ch[l-1-i];
        str[l]='\0';
        sscanf(str,"%ld=%ld+%ld",&c,&b,&a);
        printf("%s\n",(a+b==c)?"True":"False");
        if(a==0&b==0&&c==0) break;
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2504924 2007-06-28 13:10:05 Accepted 1969 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 01:08:49 | Accepted | 1969 | C | 0 | 160 | watashi | Source
