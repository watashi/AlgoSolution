#include <string.h>
#include <stdio.h>
int main()
{
    long add[45]={1,2,3,5,8,13};
    char c,cc;  /*str!!//Runtime Error //SIGSEGV string length is limited so getchar*/
    int t,i,l;
    long count;

    for(i=2;i<45;i++)
        add[i]=add[i-1]+add[i-2];
    while((cc=getchar())!='0'){
        i=0;
        count=1;
        while((c=getchar())!='\n'){
            if((cc=='1' || (cc=='2' && c<'7')) && c!='0') i++;/*!! ? 0? not valid*/
            else if(c=='0'&&i){/*this is the very point of this program*/
                count*=add[i-1];
                i=0;
            }
            else{
                count*=add[i];
                i=0;
            }
            cc=c;
        }
        count*=add[i];
        printf("%ld\n",count);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2499371 2007-06-21 19:03:09 Accepted 2202 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:09:33 | Accepted | 2202 | C | 0 | 160 | watashi | Source
