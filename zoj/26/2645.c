#include <stdio.h>
unsigned long ip[1000],mask;
unsigned long getip()
{
    int i;
    unsigned long tmp,res;

    for(i=0;i<4;i++){
        res<<=8;
        scanf("%u",&tmp);
        getchar();
        res|=tmp;
    }
    return res;
}
void putip(unsigned long ip)
{
    int i,byte[4];

    for(i=0;i<4;i++){
        byte[i]=ip%256;
        ip>>=8;
    }
    printf("%d.%d.%d.%d\n",byte[3],byte[2],byte[1],byte[0]);
}
int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF){
        mask=0;
        for(i=0;i<n;i++){
            ip[i]=getip();
            mask|=(ip[0]^ip[i]);
        }
        for(i=31;i>=0;i--)/**/
            if(mask>(1<<i)) mask|=(1<<i);/**/
        mask=~mask;
        ip[0]&=mask;
        putip(ip[0]);
        putip(mask);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2682161 2007-11-21 20:08:34 Accepted 2645 C 00:00.07 396K ¤ï¤¿¤· */

// 2012-09-07 03:11:59 | Accepted | 2645 | C | 20 | 164 | watashi | Source
