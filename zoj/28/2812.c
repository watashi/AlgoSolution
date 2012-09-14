#include <stdio.h>
int main()
{
    int i,sum;
    char ch;

    while((ch=getchar())!='#'){
        i=sum=0;
        do{
            i++;
            if(ch>='A') sum+=(ch-'A'+1)*i;
        }while((ch=getchar())!='\n');
        printf("%d\n",sum);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2476515 2007-06-02 16:23:44 Accepted 2812 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:13:13 | Accepted | 2812 | C | 0 | 160 | watashi | Source
