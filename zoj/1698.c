#include <stdio.h>
#include <string.h>
int main()
{
    char ch[80],*v="aeiou",*v2[26]={"aa","bb","cc","dd","eee","ff","gg","hh","ii","jj",
        "kk","ll","mm","nn","ooo","pp","qq","rr","ss","tt","uu","vv","ww","xx","yy","zz"};
    int flag,i,l;

    while(scanf("%s",ch),strcmp(ch,"end")){
        l=strlen(ch);
        flag=0;
        for(i=0;i<5;i++)
            if(strchr(ch,*(v+i))){
                flag=1;
                break;
            }
        if(flag){
            for(i=0;i<26;i++)
                if(strstr(ch,v2[i])){
                    flag=0;
                    break;
                }
        }
        if(flag){
            for(i=2;i<l;i++)
                if(!strchr(v,ch[i])&&!strchr(v,ch[i-1])&&!strchr(v,ch[i-2])){
                    flag=0;
                    break;
                }
                else if(strchr(v,ch[i])&&strchr(v,ch[i-1])&&strchr(v,ch[i-2])){
                    flag=0;
                    break;
                }
        }
        if(flag) printf("<%s> is acceptable.\n",ch);
        else printf("<%s> is not acceptable.\n",ch);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2501855 2007-06-24 14:56:39 Accepted 1698 C 00:00.00 2984K ¤ï¤¿¤· */

// 2012-09-07 00:57:53 | Accepted | 1698 | C | 0 | 160 | watashi | Source
