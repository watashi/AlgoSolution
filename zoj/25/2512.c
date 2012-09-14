#include <stdio.h>
#include <string.h>
int main()
{
    char str[1024];
    int i,j,k,len;

    while(scanf("%s",str)!=EOF){
        len=strlen(str);
        k=(len+1)/2;
        for(i=0;i<k;i++){
            for(j=1;str[(i-j+len)%len]==str[(i+j)%len]&&j<k;j++);
            if(j==k){
                printf("Symmetric\n%d\n",i+1);
                break;
            }
            if(str[i]==str[(i+1)%len]){
                for(j=1;str[(i-j+len)%len]==str[(i+1+j)%len]&&j<k;j++);
                if(j==k){
                    printf("Symmetric\n%d-%d\n",i+1,(i+1)%len+1);
                    break;
                }
            }
        }
        if(i==k) printf("Not symmetric\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2646674 2007-10-16 15:03:07 Accepted 2512 C 00:00.03 396K ¤ï¤¿¤· */

// 2012-09-07 03:11:17 | Accepted | 2512 | C | 10 | 160 | watashi | Source
