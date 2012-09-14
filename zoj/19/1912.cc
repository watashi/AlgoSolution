/*
//2492
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <math.h>
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdlib.h>
int main()
{
    char ch[512],str[256];
    int re,i,j,k,t,x,c;

    scanf("%d ",&re);
    while(re--){
        gets(ch);
        x=c=0;
        k=1;
        for(i=0;ch[i];){
            j=i;
            do{
                str[j-i]=ch[j];
                j++;
            }while(ch[j]!='-'&&ch[j]!='+'&&ch[j]!='='&&ch[j]!='\0');
            str[j-i]='\0';
            if(str[j-i-1]=='x'){
                if(j-i==1) t=1;
                else if(j-i==2&&str[0]=='+') t=1;
                else if(j-i==2&&str[0]=='-') t=-1;
                else t=atoi(str);
                x+=k*t;
            }
            else c-=k*atoi(str);
            if(ch[j]=='='){i=j+1;k=-1;}
            else i=j;
        }
        if(x==0&&c==0) printf("IDENTITY\n");
        else if(x==0&&c) printf("IMPOSSIBLE\n");
//      else printf("%.0lf\n",floor((double)c/(double)x));//x=x -> 0 not -0 !!
//      else printf("%d\n",c/x);//-7x=41 -> -6 not -5
        else if(x&&c==0) printf("0\n");//·ÀÖ¹Êä³ö-0.00£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
        else printf("%.0lf\n",floor((double)c/(double)x));
    }
}
*/
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdlib.h>
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <string.h>
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    char str[256];
    int re,i,j,x1,y1,c1,x2,y2,c2;
    int dx,dy,d;

    scanf("%d ",&re);
    while(re--){
        i=j=1;
        x1=y1=c1=0;
        do{
            scanf("%s",str);
            switch(str[strlen(str)-1]){
            case 'x':
                if(str[1]=='\0'||str[2]=='\0'&&str[0]=='+') x1+=i*j;
                else if(str[2]=='\0'&&str[0]=='-')  x1-=i*j;
                else x1+=i*j*atoi(str);
                j=1;break;
            case 'y':
                if(str[1]=='\0'||str[2]=='\0'&&str[0]=='+') y1+=i*j;
                else if(str[2]=='\0'&&str[0]=='-')  y1-=i*j;
                else y1+=i*j*atoi(str);
                j=1;break;
            case '+':break;
            case '-':j=-j;break;
            case '=':i=-1;break;
            default:c1-=i*j*atoi(str);j=1;break;
            }
        }while(getchar()==' ');
        i=j=1;
        x2=y2=c2=0;
        do{
            scanf("%s",str);
            switch(str[strlen(str)-1]){
            case 'x':
                if(str[1]=='\0'||str[2]=='\0'&&str[0]=='+') x2+=i*j;
                else if(str[2]=='\0'&&str[0]=='-')  x2-=i*j;
                else x2+=i*j*atoi(str);
                j=1;break;
            case 'y':
                if(str[1]=='\0'||str[2]=='\0'&&str[0]=='+') y2+=i*j;
                else if(str[2]=='\0'&&str[0]=='-')  y2-=i*j;
                else y2+=i*j*atoi(str);
                j=1;break;
            case '+':break;
            case '-':j=-j;break;
            case '=':i=-1;break;
            default:c2-=i*j*atoi(str);j=1;break;
            }
        }while(getchar()==' ');
        getchar();
        d=x1*y2-x2*y1;
        dx=c1*y2-c2*y1;
        dy=x1*c2-x2*c1;
        if(d){
            i=gcd(dx,d);j=d/i;
            if(j<0){j=-j;dx=-dx;}
            if(j==1) printf("%d\n",dx/i);
            else printf("%d/%d\n",dx/i,j);
            i=gcd(dy,d);j=d/i;
            if(j<0){j=-j;dy=-dy;}
            if(j==1) printf("%d\n",dy/i);
            else printf("%d/%d\n",dy/i,j);
        }
        else{
            if(dx==0&&dy==0){
                if(y1==0&&x1||y2==0&&x2){
                    if(y1==0&&x1){i=gcd(x1,c1);j=x1/i;dx=c1/i;}
                    else if(y2==0&&x2){i=gcd(x2,c2);j=x2/i;dx=c2/i;}
                    if(j<0){j=-j;dx=-dx;}
                    if(j==1) printf("%d\n",dx);
                    else printf("%d/%d\n",dx,j);
                    printf("don't know\n");
                }
                else if(x1==0&&y1||x2==0&&y2){
                    printf("don't know\n");
                    if(x1==0&&y1){i=gcd(y1,c1);j=y1/i;dy=c1/i;}
                    else if(x2==0&&y2){i=gcd(y2,c2);j=y2/i;dy=c2/i;}
                    if(j<0){j=-j;dy=-dy;}
                    if(j==1) printf("%d\n",dy);
                    else printf("%d/%d\n",dy,j);
                }
                else printf("don't know\ndon't know\n");
            }
            else printf("don't know\ndon't know\n");
        }
        if(re) printf("\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2632472 2007-10-05 02:57:32 Accepted 1912 C 00:00.00 388K ¤ï¤¿¤·

/*
Rank Submit time Run time Run memory Language User
1 2007-10-05 02:57:32 00:00.00 388K C ¤ï¤¿¤·
2 2007-06-03 22:42:56 00:00.00 392K C ljzhao
3 2007-06-23 08:46:40 00:00.00 392K C Snail
4 2005-09-13 23:22:59 00:00.00 396K C Leave me alone
5 2005-09-14 20:57:24 00:00.00 396K C++ qinlu
6 2006-02-02 10:46:25 00:00.00 396K C++ wcm
7 2006-03-09 23:49:23 00:00.00 396K C Ivan
8 2006-03-15 12:42:02 00:00.00 396K C++ ¿ñÕ½Ê¿
9 2006-01-27 10:50:35 00:00.00 404K C sunny
10 2005-11-24 19:51:08 00:00.00 444K C++ ant
11 2006-05-30 12:39:08 00:00.00 444K C++ I love McAfee:D
12 2006-05-30 12:39:20 00:00.00 448K C++ SHiVa
*/

// 2012-09-07 14:09:36 | Accepted | 1912 | C++ | 0 | 180 | watashi | Source
