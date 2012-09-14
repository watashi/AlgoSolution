#include <stdio.h>
#include <string.h>
#define char2int(x) (x-'0')
#define int2char(x) (i2c[x])
char i2c[128];
int main()
{
    int re,i,l,f,bin,bb,bout;
    char in[40];
    int len,num[40],out[100];

    for(i=0;i<10;i++)
        i2c[i]='0'+i;
    for(i=0;i<26;i++){
        i2c[i+10]='A'+i;i2c[i+36]='a'+i;
    }
    scanf("%d",&re);
    bin=10;
    while(re--){
        scanf("%d",&bout);
        scanf("%s",in);/*N(0<N<10^32).*/
        len=strlen(in);
        for(i=0;i<len;i++)
            num[i]=char2int(in[i]);
        l=0;
        while(1){
            f=0;
            for(i=0;i<len-1;i++)
                if(num[i]){
                    f=1;
                    num[i+1]+=(num[i]%bout)*bin;
                    num[i]/=bout;
                }
            if(num[i]) f=1;
            out[l++]=num[i]%bout;
            num[i]/=bout;
            if(f==0) break;
        }
        /*****/
        bb=bout>>1;
        for(i=0;i<l;i++)
            if(out[i]>bb){out[i]-=bout;out[i+1]++;}
        if(out[l-1]==0) l--;
        while(l--){
            if(out[l]<0){putchar('-');out[l]=-out[l];}
            putchar(int2char(out[l]));
        }
        /*****/
        putchar('\n');
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2658342 2007-10-25 19:26:39 Accepted 2143 C 00:00.00 400K わたし */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2658346 2007-10-25 19:31:33 Accepted 2143 C 00:00.00 392K わたし */

/*
Rank Submit time Run time Run memory Language User
1 2005-09-14 01:12:14 00:00.00 392K C Leave me alone
2 2005-10-13 00:00:59 00:00.00 392K C++ 噴定岻朔
3 2006-02-02 11:44:38 00:00.00 392K C++ wcm
4 2007-03-08 12:53:34 00:00.00 392K C++ 9911
5 2007-10-25 19:31:33 00:00.00 392K C わたし
6 2006-08-18 15:23:48 00:00.00 436K C++ sunny
7 2006-10-17 14:34:43 00:00.00 444K C++ ZengXiaoQi
8 2006-05-04 15:27:35 00:00.00 836K C++ shelling
*/

// 2012-09-07 01:14:06 | Accepted | 2143 | C | 0 | 160 | watashi | Source
