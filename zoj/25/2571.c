#include <stdio.h>
char str[255];
void printit(char *str,int n)
{
    int i,k,re,count;
    char sub[250],*p;

    if(n==0) n=1;
    for(k=0;k<n;k++){
        re=0;
        p=str;
        while(*p){
            if('0'<=*p&&*p<='9'){
                re*=10;
                re+=*p-'0';
            }
            else{
                if(*p=='('){
                    i=0;
                    count=1;
                    while(count){
                        p++;
                        if(*p=='(') count++;
                        else if(*p==')') count--;
                        sub[i++]=*p;
                    }
                    sub[i-1]='\0';
                    printit(sub,re);
                    re=0;
                }
                else{
                    if(re==0) re=1;
                    for(i=0;i<re;i++)
                        putchar(*p);
                    re=0;
                }
            }
            p++;
        }
    }
}
int main()
{
    int i,n;

    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%s",str);
        printit(str,1);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2510586 2007-07-06 23:56:32 Accepted 2571 C 00:00.00 388K ¤ï¤¿¤· */

/*
Rank Submit time Run time Run memory Language User
1 2006-04-25 13:08:19 00:00.00 244K FPC Shiva
2 2006-08-22 20:08:51 00:00.00 244K FPC ßíÍæMJ¸ÂMJ
3 2006-04-25 13:07:40 00:00.00 248K FPC con
4 2006-08-22 20:06:43 00:00.00 248K FPC ßíÍæMJ
5 2005-10-22 17:16:00 00:00.00 388K C minijacky
6 2005-10-22 21:53:12 00:00.00 388K C Lavigne
7 2006-04-16 21:35:59 00:00.00 388K C ab
8 2006-10-02 13:51:03 00:00.00 388K C Ray
9 2006-11-12 23:15:58 00:00.00 388K C ¹ÛÏÍ
10 2007-07-06 23:56:32 00:00.00 388K C ¤ï¤¿¤·
*/
/* //yoshi! */

// 2012-09-07 03:11:41 | Accepted | 2571 | C | 0 | 160 | watashi | Source
