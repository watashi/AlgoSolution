#include <stdio.h>
int main()
{
    struct{
        char pst[16];
        float ss;
        int mw,ms;
    }pp[3]={{"Wide Receiver", 4.5, 150, 200 },
            {"Lineman", 6.0, 300, 500 },
            {"Quarterback", 5.0, 200, 300 }},*p=pp;
    float ss;
    int i,iF,mw,ms;

    while(scanf("%f%d%d",&ss,&mw,&ms),ss){
        for(iF=i=0;i<3;i++)
            if((p+i)->ss>=ss&&(p+i)->mw<=mw&&(p+i)->ms<=ms){
                if(iF) printf(" ");
                printf("%s",(p+i)->pst);
                iF=1;
            }
        if(!iF) printf("No positions");
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2478886 2007-06-03 23:43:00 Accepted 2321 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 01:18:59 | Accepted | 2321 | C | 0 | 160 | watashi | Source
