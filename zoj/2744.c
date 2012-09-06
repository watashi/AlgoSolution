/*
#include <stdio.h>
int main()
{
    char ch[5005];
    int i,j,k;
    long count;

    while(gets(ch+1)){
        count=0;
        ch[0]='\n';
        for(i=1;ch[i];i++){
            j=1;
            while(ch[i-j]==ch[i+j]) j++;
            count+=j;
        }
        for(k=1,i=2;ch[i];i++){
            j=0;
            while(ch[k-j]==ch[i+j]) j++;
            count+=j;
            k=i;
        }
        printf("%ld\n",count);
    }
}
*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2508732 2007-07-04 00:58:18 Accepted 2744 C 00:00.06 396K わたし */
#include <stdio.h>
int main()
{
    char ch[5005];
    int i,j,k;
    long count;

    while(gets(ch+1)){
        count=0;
        ch[0]='\n';
        for(i=1,j=2;ch[i];j++){
            k=1;
            while(ch[i-k]==ch[i+k]) k++;
            count+=k;
            k=0;
            while(ch[i-k]==ch[j+k]) k++;
            count+=k;
            i=j;
        }
        printf("%ld\n",count);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2508733 2007-07-04 01:03:07 Accepted 2744 C 00:00.07 392K わたし */
/* //2508732 2007-07-04 00:58:18 Accepted 2744 C 00:00.06 396K わたし */


/* //GOOD */
/* //13 2007-07-04 00:58:18 00:00.06 396K C わたし */

// 2012-09-07 01:37:36 | Accepted | 2744 | C | 30 | 160 | watashi | Source
