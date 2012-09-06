#include <stdio.h>
int main()
{
    int ri,repeat,i,count;
    char ch[108];

    scanf("%d\n",&repeat);
    for(ri=1;ri<=repeat;ri++){
        gets(ch);
        count=1;
        i=-1;
        while(ch[++i]!='\0'){
            if(ch[i]!=ch[i+1]){
                if(count>1) printf("%d%c",count,ch[i]);
                else printf("%c",ch[i]);
                count=1;
            }
            else{
                count++;
            }
        }
        printf("\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2475115 2007-06-01 17:37:44 Accepted 2478 C 00:00.00 388K ¤ï¤¿¤·

// 2012-09-07 01:24:06 | Accepted | 2478 | C++ | 0 | 180 | watashi | Source
