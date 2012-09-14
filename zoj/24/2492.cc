#include <cstdio> // auto fix CE
#include <math.h>
#include <cstdio> // auto fix CE
#include <stdio.h>
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
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2628080 2007-10-02 03:20:01 Accepted 2492 C 00:00.00 388K ¤ï¤¿¤·

// 2012-09-07 14:10:39 | Accepted | 2492 | C++ | 0 | 180 | watashi | Source
