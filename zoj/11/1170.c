#include <stdio.h>
#include <string.h>
int main()
{
    char m[16],n[16];
    int i,j,count,lm,ln,max,f,t,a,b,temp;

    while(1){
        scanf("%s",m);
        if(!strcmp(m,"-1")) break;
        scanf("%s",n);
        max=0;
        lm=strlen(m);
        ln=strlen(n);
        for(i=-lm+1;i<ln;i++){
            f=(0>i)?0:i;
            t=(ln<i+lm)?ln:(i+lm);
            count=0;
            for(j=f;j<t;j++)
                if(m[j-i]==n[j]) count++;
            if(count>max) max=count;
        }
        a=lm+ln;
        b=2*max;
        if(b==0) printf("appx(%s,%s) = 0\n",m,n);
        else if(a==b) printf("appx(%s,%s) = 1\n",m,n);
        else{
            while(a%b!=0){
            t=a;
            a=b;
            b=t%b;
            }
            printf("appx(%s,%s) = %d/%d\n",m,n,2*max/b,(lm+ln)/b);
        }
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2472225 2007-05-30 19:10:18 Accepted 1170 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 00:39:54 | Accepted | 1170 | C | 0 | 160 | watashi | Source
