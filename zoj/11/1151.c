#include <stdio.h>
int main()
{
    char alpha[100];
    int i,n,ri,repeat,ri2,repeat2;

    scanf("%d\n\n",&repeat);
    for(ri=1;ri<=repeat;ri++){
        scanf("%d\n",&repeat2);
        if(ri>1) printf("\n");
        for(ri2=1;ri2<=repeat2;ri2++){
            i=0;
            while(1){
                alpha[i]=getchar();
                if(alpha[i]=='\n'){
                    n=i-1;
                    for(i=n;i>=0;i-=1)
                        printf("%c",alpha[i]);
                    printf("\n");
                    i=0;
                    break;
                }
                else if(alpha[i]==' '){
                    n=i-1;
                    for(i=n;i>=0;i-=1)
                        printf("%c",alpha[i]);
                    printf(" ");
                    i=0;
                }
                else i++;
            }
        }
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464505 2007-05-26 23:01:46 Accepted 1151 C 00:00.04 396K ¤ï¤¿¤· */

// 2012-09-07 02:56:52 | Accepted | 1151 | C | 20 | 160 | watashi | Source
