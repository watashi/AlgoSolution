#include <stdio.h>
#include <string.h>
char s[108][108];
int main()
{
    int i,j,k,p,t,ans;
    char str[40];

    while(scanf("%d%d ",&p,&t)!=EOF){
        memset(s,0,sizeof(s));
        while(gets(str)){
            if(!strcmp(str,"")) break;
            sscanf(str,"%d%d",&i,&j);
            i--;j--;
            s[i][j]=1;
        }
        ans=0;
        for(i=0;i<p;i++){
            if(s[i][100]) continue;
            s[i][100]=1;
            for(j=1;j<p;j++){
                if(s[j][100]) continue;
                for(k=0;k<t&&s[i][k]==s[j][k];k++);
                if(k==t) s[j][100]=1;
            }
            ans++;
        }
        printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2650089 2007-10-19 11:32:00 Accepted 1900 C 00:00.00 404K ¤ï¤¿¤· */

// 2012-09-07 03:06:42 | Accepted | 1900 | C | 0 | 172 | watashi | Source
