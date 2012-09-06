#include <stdio.h>
#include <string.h>
long max;
char a[2000],b[2000];
void find(int i,int j,long count)
{
    char *pa,*pb;

    if(a[i]=='\0'||b[j]=='\0'){
        if(count>max) max=count;
    }
    else if(a[i]==b[j]) find(i+1,j+1,count+1);
    else{
        pa=strchr(&a[i],b[j]);
        if(pa!=NULL) find(pa-a+1,j+1,count+1);
        pb=strchr(&b[j],a[i]);
        if(pb!=NULL) find(i+1,pb-b+1,count+1);
        find (i+1,j+1,count);
    }
}
int main()
{
    while(scanf("%s%s",a,b)!=EOF){
        max=0;
        find(0,0,0);
        printf("%ld\n",max);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2516861 2007-07-12 23:10:09 Accepted 1733 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:04:13 | Accepted | 1733 | C | 0 | 164 | watashi | Source
