#include <stdio.h>
#include <string.h>
int main()
{
    struct election{
        char name[82],party[82];
        int vote;
    }a[22],*p=a;
    char ch[82];
    int i,j,n,m,x,y;

    while(scanf("%d ",&n)/*??input!!*/!=EOF){
        for(i=0;i<n;i++){
            gets((p+i)->name);
            gets((p+i)->party);
            (p+i)->vote=0;
        }
        scanf("%d ",&m);/*??input!!*/
        for(j=0;j<m;j++){
            gets(ch);
            for(i=0;i<n;i++)
                if(!strcmp(ch,(p+i)->name)) {ch,(p+i)->vote++;break;}
        }
        x=y=0;
        for(i=1;i<n;i++){
            if((p+i)->vote>(p+x)->vote) x=y=i;
            else if((p+i)->vote==(p+x)->vote) y=i;
        }
        if(x==y) puts((p+x)->party);
        else puts("tie");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2503364 2007-06-26 13:14:50 Accepted 1854 C 00:00.01 388K gl hf */

// 2012-09-07 03:05:32 | Accepted | 1854 | C | 0 | 160 | watashi | Source
