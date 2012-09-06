#include <stdio.h>
int main()
{
    int i,j,n,n0,count;
    char ch[53];

    while(scanf("%d ",&n),n){
        n0=n;
        n=count=i=0;
        while(ch[i]=getchar(),ch[i]!='\n'){
            for(j=0;j<i;j++){
                if(ch[i]==ch[j]){
                    n--;
                    break;
                }
            }
            if(i==j) n++;
            if(n>n0){
                count++;
                n--;
                ch[i]=' ';
            }
            i++;
        }
        if(count==0) printf("All customers tanned successfully.\n");
        else printf("%d customer(s) walked away.\n",count/2);
    }
}
/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469500 2007-05-29 12:27:53 Accepted 1405 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 00:48:32 | Accepted | 1405 | C | 0 | 160 | watashi | Source
