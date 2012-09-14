#include <stdio.h>
int l;
char str[30],ch[30];
void undoJ()
{
    strcpy(ch,str);
    str[0]=ch[l-1];
    strcpy(str+1,ch);
    str[l]='\0';
}
void undoC()
{
    strcpy(ch,str);
    strcpy(str,ch+1);
    str[l-1]=ch[0];
    str[l]='\0';
}
void undoE()
{
    int i,x=l/2,y=(l+1)/2;

    strcpy(ch,str);
    for(i=0;i<x;i++){
        str[i]=ch[y+i];
        str[y+i]=ch[i];
    }
}
void undoA()
{
    int i,j;
    char c;

    for(i=-1,j=l;++i<--j;)  {c=str[i];str[i]=str[j];str[j]=c;}
}
void undoP()
{
    int i;

    for(i=0;i<l;i++){
        if(str[i]=='0') str[i]='9';
        else if(str[i]>'0'&&str[i]<='9') str[i]-=1;
    }
}
void undoM()
{
    int i;

    for(i=0;i<l;i++){
        if(str[i]=='9') str[i]='0';
        else if(str[i]>='0'&&str[i]<'9') str[i]+=1;
    }
}
int main()
{
    int i,j,n;
    char cmd[10];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%s",cmd,str);
        l=strlen(str);
        j=strlen(cmd);
        while(j--){
            switch(cmd[j]){
            case 'J':undoJ();break;
            case 'C':undoC();break;
            case 'E':undoE();break;
            case 'A':undoA();break;
            case 'P':undoP();break;
            case 'M':undoM();break;
            }
        }
        printf("%s\n",str);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2511440 2007-07-08 10:58:29 Accepted 1737 C 00:00.00 384K ¤ï¤¿¤· */

/*
Rank Submit time Run time Run memory Language User
1 2005-10-15 10:53:42 00:00.00 384K C yofuke
2 2005-11-01 13:25:16 00:00.00 384K C++ KISS_PCL
3 2005-11-30 22:00:49 00:00.00 384K C Lavigne
4 2006-03-10 12:27:49 00:00.00 384K C++ -_-
5 2006-03-11 21:57:49 00:00.00 384K C++ fluke@S.G.U
6 2006-04-03 22:08:19 00:00.00 384K C++ lu
7 2006-04-24 12:46:43 00:00.00 384K C++ Åè¾°ÄÐ^_^
8 2006-07-08 17:43:22 00:00.00 384K C++ zouping514
9 2006-07-09 14:08:10 00:00.00 384K C++ snow
10 2007-07-08 10:58:29 00:00.00 384K C ¤ï¤¿¤·
11 2005-09-13 15:41:17 00:00.00 388K C++ Ñ¦ÔÚÔÀ
12 2005-09-13 22:02:53 00:00.00 388K C Leave me alone
*/

// 2012-09-07 03:04:19 | Accepted | 1737 | C | 0 | 160 | watashi | Source
