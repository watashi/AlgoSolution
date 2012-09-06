#include <stdio.h>
int main()
{
    struct clock{
        int hh,mm;
        double t;
    }i,f;
    double tt[23];
    int k,count;

    for(k=0;k<23;k++){
        tt[k]=60.0/11.0*k+60*k;
    }
    printf("Program 3 by team X\n");
    printf("Initial time  Final time  Passes\n");
    while(scanf("%d%d%d%d",&i.hh,&i.mm,&f.hh,&f.mm)!=EOF){
        printf("       %02d:%02d       %02d:%02d",i.hh,i.mm,f.hh,f.mm);
        if(i.hh==12) i.hh=0;
        if(f.hh==12) f.hh=0;
        i.t=60*i.hh+i.mm;
        f.t=60*f.hh+f.mm;
        if(f.t<i.t) f.t+=60*12;
        count=0;
        k=-1;
        while(i.t>tt[++k]);
        while(f.t>tt[k++]) count++;
        printf("%8d\n",count);
    }
    printf("End of program 3 by team X\n");

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2504152 2007-06-27 13:27:15 Accepted 1122 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 02:56:33 | Accepted | 1122 | C | 0 | 160 | watashi | Source
