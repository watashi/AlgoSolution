#include <stdio.h>
int main()
{
    struct{
        char ch[50];
    }DNA[100],dna;
    int ri,repeat,i,j,k,temp,length,number,inversion[100];

    scanf("%d\n\n",&repeat);
    for(ri=1;ri<=repeat;ri++){
        if(ri-1) printf("\n");
        scanf("%d %d\n",&length,&number);
        for(i=0;i<number;i++){
            inversion[i]=0;
            for(j=0;j<length;j++){
                DNA[i].ch[j]=getchar();
                for(k=0;k<j;k++)
                    if(DNA[i].ch[k]>DNA[i].ch[j]) inversion[i]++;
            }
            getchar();
        }
        for(i=0;i<number;i++){
            k=i;
            for(j=i+1;j<number;j++)
                if(inversion[j]<inversion[k]) k=j;
            temp=inversion[k];
            inversion[k]=inversion[i];
            inversion[i]=temp;
            dna=DNA[k];
            DNA[k]=DNA[i];
            DNA[i]=dna;
        }
        for(i=0;i<number;i++){
            for(j=0;j<length;j++)
                printf("%c",DNA[i].ch[j]);
            printf("\n");
        }
    }

    return 0;   /* NZEC */
}


/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464506 2007-05-26 23:02:48 Accepted 1188 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 02:57:28 | Accepted | 1188 | C | 0 | 160 | watashi | Source
