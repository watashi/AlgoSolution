#include <stdio.h>
int main()
{
    int re=0,none,i,n,def[26],l,r;
    char ch[8];

    while(scanf("%d",&n),n){
        getchar();
        def[0]=1;
        for(i=1;i<26;i++)
            def[i]=0;
        for(i=0;i<n;i++){
            gets(ch);
            l=ch[0]-'a';
            r=ch[4]-'a';
            if(def[r]==1) def[l]=1;
            else if(def[r]==0) def[l]=0;
        }
        printf("Program #%d\n",++re);
        none=1;
        for(i=0;i<26;i++)
            if(def[i]==1){
                printf("%c ",'a'+i);
                none=0;
            }
        if(none) printf("none\n");
        else printf("\n");
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2493191 2007-06-16 04:39:57 Accepted 1244 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 00:43:03 | Accepted | 1244 | C | 0 | 160 | watashi | Source
