#include <stdio.h>
#include <string.h>
int main()
{
    char str1[88],str2[88];
    int i,n,t,j,k,len1,len2;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&t);
        getchar();      /*!!*/
        gets(str1);
        gets(str2);
        len1=strlen(str1);
        len2=strlen(str2);
        j=0;
        while(str1[j]==str2[j]&&str2[j]) j++;
        k=j;
        printf("%d\n",(len1-k+len2-k)*t);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2492176 2007-06-14 21:35:33 Accepted 1582 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:02:51 | Accepted | 1582 | C | 0 | 160 | watashi | Source
