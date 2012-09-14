#include <stdio.h>
#include <string.h>
#define char2int(x) (x-'@')
char str[15],tmp[6],ans[6];
int len,key;
int power(int x,int y)
{
    int i,res=1;

    for(i=1;i<=y;i++)
        res*=x;
    return res;
}
void dfs(int d,int x)
{
    int i;

    if(d==5){
        if(x==key){
            tmp[5]='\0';
            if(strcmp(ans,"")==0 || strcmp(ans,tmp)<0) strcpy(ans,tmp);
        }
    }
    else{
        for(i=0;i<len;i++){
            if(str[i]=='\0') continue;
            tmp[d]=str[i];
            str[i]='\0';
            if(d&1) dfs(d+1,x-power(char2int(tmp[d]),d+1));
            else dfs(d+1,x+power(char2int(tmp[d]),d+1));
            str[i]=tmp[d];
        }
    }
}
int main()
{
    while(scanf("%d%s",&key,str)!=EOF && key||strcmp(str,"END")){
        strcpy(ans,"");
        len=strlen(str);
        dfs(0,0);
        if(strcmp(ans,"")) printf("%s\n",ans);
        else printf("no solution\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2658988 2007-10-26 11:46:37 Accepted 1403 C 00:00.05 384K ¤ï¤¿¤· */

// 2012-09-07 00:48:26 | Accepted | 1403 | C | 20 | 160 | watashi | Source
