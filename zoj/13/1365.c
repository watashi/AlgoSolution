#include <stdio.h>
int main()
{
    char ch;
    double a,sum;

    while((ch=getchar())!='#'){
        sum=0;
        while(1){
            while((ch=getchar())<'0'||ch>'9');
            if(ch=='0'){
                ch=getchar();
                break;
            }
            a=0;
            while(ch!=' '){
                a=10*a+ch-'0';
                ch=getchar();
            }
            ch=getchar();
            switch(ch){
            case 'F':sum+=2*a;break;
            case 'B':sum+=3*a/2;break;
            case 'Y':if(a<500) sum+=500;
                else sum+=a;
                break;
            }
        }
        printf("%.0lf\n",sum);
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2450331 2007-05-20 16:08:14 Accepted 1365 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:00:25 | Accepted | 1365 | C | 0 | 160 | watashi | Source
