#include <stdio.h>
int main()
{
    char str[10];
    int i,j,k,map[26][26];
    int ri,re,n;

    scanf("%d",&re);
    for(ri=1;ri<=re;ri++){
        scanf("%d",&n);
        for(i=0;i<26;i++)
            for(j=0;j<26;j++)
                map[i][j]=0;
        while(n--){
            scanf("%s",str);
            if(str[1]=='<') map[str[0]-'A'][str[2]-'A']=2;
            else if(str[1]=='>') map[str[2]-'A'][str[0]-'A']=2;
        }
        for(k=0;k<26;k++)
            for(i=0;i<26;i++)
                for(j=0;j<26;j++)
                    if(map[i][k]&&map[k][j]&&map[i][j]==0) map[i][j]=1;
        printf("Case %d:\n",ri);
        k=0;
        for(i=0;i<26;i++)
            for(j=0;j<26;j++)
                if(map[i][j]==1){
                    printf("%c<%c\n",'A'+i,'A'+j);
                    k=1;
                }
        if(k==0) printf("NONE\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2595476 2007-09-04 03:06:38 Accepted 1589 C 00:00.01 396K ¤ï¤¿¤· */

// 2012-09-07 03:02:57 | Accepted | 1589 | C | 0 | 160 | watashi | Source
