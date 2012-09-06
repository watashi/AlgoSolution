/*
#include <stdio.h>
int main()
{
    int ri,repeat,tab,blank;
    char oldch,ch;

    scanf("%d",&repeat);
    getchar();
    for(ri=1;ri<=repeat;ri++){
        blank=tab=0;
        oldch='\0';
        while(1){
            ch=getchar();
            if(ch==' '&&oldch==' ') blank++;
            else if(ch=='\n'&&oldch==' ') blank++;
            else if(ch=='\t') tab++;
            else if(ch=='#'&&oldch=='#'){
                getchar();
                break;
            }
            oldch=ch;
        }
        printf("%d tab(s) replaced\n%d trailing space(s) removed\n",tab,blank);
    }
}
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int ri,repeat,i,len,tab,blank;
    char ch[1024];

    scanf("%d",&repeat);
    getchar();
    for(ri=1;ri<=repeat;ri++){
        blank=tab=0;
        while(gets(ch),strcmp(ch,"##")){
            len=strlen(ch);
            for(i=0;i<len;i++)
                if(ch[i]=='\t') tab++;
            i=len;
            while(--i>=0){
                if(ch[i]==' ') blank++;
                else if(ch[i]=='\t') blank+=4;/*(from cc98)<=>这题ms如果tab在最后面 换成space之后那4个space还要算到trailing spaces里面。。 */
                else break;
            }
        }
        printf("%d tab(s) replaced\n",tab);
        printf("%d trailing space(s) removed\n",blank);
    }

    return 0;   /* NZEC */
}


/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2494259 2007-06-17 01:11:54 Accepted 2851 C 00:00.00 392K わたし */

// 2012-09-07 03:14:01 | Accepted | 2851 | C | 0 | 160 | watashi | Source
