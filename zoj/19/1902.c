#include <stdio.h>
#include <string.h>
int main()
{
    struct hay{
        char job[17];
        long money;
    }a[1000];
    int i,n,m;
    long sum;
    char word[18];

    while(scanf("%d%d",&m,&n)!=EOF){
        for(i=0;i<m;i++)
            scanf("%s%ld",&a[i].job,&a[i].money);
        while(n--){
            sum=0;
            while(scanf("%s",word)){
                if(!strcmp(word,".")) break;
                for(i=0;i<m;i++)
                    if(!strcmp(word,a[i].job)){
                        sum+=a[i].money;
                        break;
                    }
            }
            printf("%ld\n",sum);
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2496943 2007-06-19 12:55:48 Accepted 1902 C 00:00.00 408K ¤ï¤¿¤· */

// 2012-09-07 03:06:48 | Accepted | 1902 | C | 0 | 160 | watashi | Source
