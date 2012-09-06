#include <string.h>
#include <stdio.h>
const char *month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
const int a[12]={96+20,128+21,160+22,192+22,224+22,256+22,288+22,320+22,352+22,384+21,416+20,448+19};
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int data2con(char str[],int x)
{
    int i,t;

    for(i=0;i<12;i++)
        if(!strcmp(month[i],str)) t=(i<<5)+x;
    if(t<84) t+=384;
    for(i=0;i<12;i++)
        if(t<=a[i]) return i;
    return -1;
}
int main()
{
    char str[55];
    int n,x,i,m,c[12],cc;

    while(scanf("%d",&n)!=EOF && n){
        for(i=0;i<12;i++)
            c[i]=0;
        while(n--){
            scanf("%s%d",str,&x);
            c[data2con(str,x)]++;
        }
        cc=0;
        for(i=0;i<12;i++)
            cc=gcd(c[i],cc);
        m=0;
        for(i=0;i<12;i++){
            c[i]/=cc;
            if(c[i]>m) m=c[i];
        }
        while(m>=0){
            for(i=0;i<12;i++){
                if(m&&m==c[i]) sprintf(str+(i<<2),"%3d ",cc*c[i]);
                else sprintf(str+(i<<2),"%3s ",(m<c[i])?"XX":"");
            }
            i=47;
            while(str[i]==' ') i--;
            str[i+1]='\0';
            puts(str);
            m--;
        }
        printf("------------------------------------------------\n");
        printf(" Ar  Ta  Ge  Ca  Le  Vi  Li  Sc  Sa  Ca  Aq  Pi\n\n");
    }

    return 0;   /* NZEC */
}


/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2674526 2007-11-13 17:31:05 Accepted 2726 C 00:00.00 388K ¤ï¤¿¤· */

/*
Rank Submit time Run time Run memory Language User
1 2006-04-27 22:38:12 00:00.00 388K C++ neal
2 2007-11-13 17:31:05 00:00.00 388K C ¤ï¤¿¤·
3 2006-04-14 23:32:42 00:00.00 392K C++ yext
4 2006-04-15 00:40:34 00:00.00 392K C mj
5 2006-04-15 10:26:49 00:00.00 392K C pluskid
6 2006-04-18 00:05:15 00:00.00 392K C Jelly
7 2006-04-20 01:06:08 00:00.00 392K C++ honey
8 2006-04-21 11:20:27 00:00.00 392K C++ SunLiwen
9 2006-04-22 17:30:30 00:00.00 392K C ÇâÑõ»¯Í­
10 2006-05-02 13:48:48 00:00.00 392K C++ ÁõÈôÓ¢
11 2006-05-09 16:41:05 00:00.00 392K C intx
12 2006-06-02 23:24:18 00:00.00 392K C++ wcm
13 2006-11-25 11:47:46 00:00.00 392K C++ bea
14 2007-03-24 22:04:17 00:00.00 392K C++ easy
15 2007-05-18 11:13:31 00:00.00 392K C++ 9911
16 2007-06-09 21:46:12 00:00.00 392K C++ yrt
17 2007-09-08 20:21:35 00:00.00 392K C++ chenxizju
18 2007-10-06 22:16:39 00:00.00 392K C++ Why not accepted?
19 2006-04-14 22:34:55 00:00.00 396K C++ Anut
20 2006-04-15 08:45:11 00:00.00 396K C++ zr
*/

// 2012-09-07 03:12:18 | Accepted | 2726 | C | 0 | 160 | watashi | Source
