#include <stdio.h>
#include <stdlib.h>
char ca[108],cb[108];
int a[26],b[26];
int cmp(const void *pa,const void *pb)
{
    return (*(int *)pa==*(int *)pb)?0:((*(int *)pa<*(int *)pb)?-1:1);
}
int main()
{
    int i;

    while(scanf("%s%s",ca,cb)!=EOF){
        for(i=0;i<26;++i)
            a[i]=b[i]=0;
        for(i=0;ca[i];++i)
            ++a[ca[i]-'A'];
        for(i=0;cb[i];++i)
            ++b[cb[i]-'A'];
        qsort(a,26,sizeof(int),cmp);
        qsort(b,26,sizeof(int),cmp);
        for(i=0;i<26;++i)
            if(a[i]!=b[i]) break;
        printf("%s\n",(i==26)?"YES":"NO");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2682879 2007-11-22 21:15:46 Accepted 2658 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 03:12:12 | Accepted | 2658 | C | 0 | 160 | watashi | Source
