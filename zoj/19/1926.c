#include <stdio.h>
int main()
{
    int min,max,x;
    char ch;

    scanf("%d",&x);
    while(x!=0){
        max=11;
        min=-1;
        getchar();getchar();getchar();getchar();getchar();ch=getchar();
        while(getchar()!='\n');
        while(ch!='t'){
            if(ch=='h') max=(max<x)?max:x;
            else if(ch=='l') min=(min>x)?min:x;
            scanf("%d\n",&x);
            getchar();getchar();getchar();getchar();ch=getchar();
            while(getchar()!='\n');
        }
        if(max>x&&min<x) printf("Stan may be honest\n");
        else printf("Stan is dishonest\n");
        scanf("%d",&x);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2462567 2007-05-25 18:02:24 Accepted 1926 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 01:06:50 | Accepted | 1926 | C | 0 | 160 | watashi | Source
