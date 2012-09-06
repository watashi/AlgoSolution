#include <stdio.h>
#include <string.h>
int main()
{
    struct account{
        char un[12],pw[12];
    }temp,save[1000];
    char str[2][5]={"10lO","@%Lo"};
    int i,j,k,len,n;

    while(scanf("%d",&n),n){
        k=0;
        while(n--){
            scanf("%s%s",temp.un,temp.pw);
            /*save[i]=temp;----wrong*/
            strcpy(save[k].pw,temp.pw);
            len=strlen(temp.pw);
            for(i=0;i<4;i++)
                for(j=0;j<len;j++)
                    if(save[k].pw[j]==str[0][i]) save[k].pw[j]=str[1][i];
            if(strcmp(save[k].pw,temp.pw)){
                strcpy(save[k].un,temp.un);
                k++;
            }
        }
        if(!k) printf("No account is modified.\n");
        else{
            printf("%d\n",k);
            for(j=0;j<k;j++)
                printf("%s %s\n",save[j].un,save[j].pw);
        }
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2498026 2007-06-20 15:06:23 Accepted 2514 C 00:00.00 412K ¤ï¤¿¤· */

// 2012-09-07 01:26:15 | Accepted | 2514 | C | 0 | 160 | watashi | Source
