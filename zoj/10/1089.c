#include <stdio.h>
int main()
{
    int i,n,x[55],m[7]={0},blank=0;

    while(scanf("%d",&n),n){
        if(blank) printf("\n");
        else blank=1;
        for(i=1;i<=n;i++)
            scanf("%d",&x[i]);
        for(m[1]=m[0]+1;m[1]<=n;m[1]++){
            for(m[2]=m[1]+1;m[2]<=n;m[2]++){
                for(m[3]=m[2]+1;m[3]<=n;m[3]++){
                    for(m[4]=m[3]+1;m[4]<=n;m[4]++){
                        for(m[5]=m[4]+1;m[5]<=n;m[5]++){
                            for(m[6]=m[5]+1;m[6]<=n;m[6]++){
                                for(i=1;i<6;i++)
                                    printf("%d ",x[m[i]]);
                                printf("%d\n",x[m[6]]);
                            }
                        }
                    }
                }
            }
        }
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2490577 2007-06-13 15:57:04 Accepted 1089 C 00:00.01 396K ¤ï¤¿¤· */

// 2012-09-07 00:36:09 | Accepted | 1089 | C | 0 | 160 | watashi | Source
