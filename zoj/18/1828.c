#include <stdio.h>
void add(int *pa,int *pb,int *pd)
{
    int i;

    for(i=0;i<*pd;i++)
        if((*(pa+i)=*(pa+i)+*(pb+i))>9){
            *(pa+i)-=10;
            (*(pa+i+1))++;
        }
    if(*(pa+i)) (*pd)++;
}
int main()
{
    static int i,n,digit,a[1000],b[1000];
    int *pa=a,*pb=b,*pd=&digit,*pt;

    while(scanf("%d",&n)!=EOF){
        for(i=0;i<1000;i++)
            a[i]=b[i]=0;
        a[0]=b[0]=digit=1;
        for(i=3;i<=n;i++){
            add(pa,pb,pd);
            pt=pa;
            pa=pb;
            pb=pt;
        }
        for(i=digit-1;i>=0;i--)
            printf("%d",*(pb+i));
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2470199 2007-05-29 17:56:32 Accepted 1828 C 00:00.03 400K ¤ï¤¿¤· */

// 2012-09-07 03:05:14 | Accepted | 1828 | C | 20 | 168 | watashi | Source
