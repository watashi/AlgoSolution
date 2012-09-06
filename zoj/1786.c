#include <stdio.h>
int main()
{
    int re,i,j,n,root[26]={1},a[50];

    for(i=1;i<26;i++)
        root[i]=root[i-1]+root[i-1]+1;
    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        printf("%d [",n);
        i=25;j=0;
        while(n){
            if(root[i]>n) i--;
            else {n-=root[i];a[j++]=i;}
        }
        for(j--;j>=0;j--){
            printf("%d",a[j]);
            if(j) printf(",");
        }
        printf("]\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2595958 2007-09-04 16:12:28 Accepted 1786 C++ 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 01:00:38 | Accepted | 1786 | C | 0 | 160 | watashi | Source
