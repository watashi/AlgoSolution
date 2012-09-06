/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int findnext(int x,char key[27])
{
    int i,res;

    res=-1;
    for(i=0;key[i];i++)
        if(key[i]<=key[x]) continue;
        else if(res==-1||key[i]<key[res]) res=i;
    return res;
}
int main()
{
    char key[28],str[101],text[26][100];
    int re,len,t,i,j,r,c;

    scanf("%d",&re);
    while(re--){
        scanf("%s%s",key,str);
        len=strlen(key);
        for(i=0;str[i];i++)
            text[i/len][i%len]=str[i];
        r=i/len;c=i%len;
        i=len;
        while((i=findnext(i,key))!=-1){
            for(j=0;j<r;j++)
                putchar(toupper(text[j][i]));
            if(i<c) putchar(toupper(text[j][i]));
        }
        putchar('\n');
    }
}
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int findnext(int x,char key[27])
{
    int i,res;

    res=-1;
    for(i=0;key[i];i++)
        if(key[i]<=key[x]) continue;
        else if(res==-1||key[i]<key[res]) res=i;
    return res;
}
int main()
{
    char key[28],str[101],text[100][26];
    int re,len,l,t,i,j,k,r,c;

    scanf("%d",&re);
    while(re--){
        scanf("%s%s",key,str);
        len=strlen(key);
        l=strlen(str);
        r=l/len;c=l%len;k=0;
        for(j=findnext(len,key);j!=-1;j=findnext(j,key)){
            for(i=0;i<r;i++)
                text[i][j]=str[k++];
            if(j<c) text[r][j]=str[k++];
        }
        for(i=0;i<r;i++)
            for(j=0;j<len;j++)
                putchar(tolower(text[i][j]));
        for(j=0;j<c;j++)
            putchar(tolower(text[i][j]));
        putchar('\n');
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2603752 2007-09-10 22:36:19 Accepted 2635 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 01:32:55 | Accepted | 2635 | C | 0 | 160 | watashi | Source
