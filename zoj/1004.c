#include <stdio.h>
char a[80],b[80],stack[160];
void doit(int i,int j,int k,int n,char t[])
{
    int l;

    if(b[j]=='\0'){
        for(l=0;l<n;l++)
            printf("%c ",stack[l]);
        printf("\n");
    }
    else{
        if(k==0){
            if(a[i]){
                t[k]=a[i];
                stack[n]='i';
                doit(i+1,j,k+1,n+1,t);
            }
            else return;
        }
        else if(t[k-1]==b[j]){
            if(a[i]){
                t[k]=a[i];
                stack[n]='i';
                doit(i+1,j,k+1,n+1,t);
            }
            stack[n]='o';
            doit(i,j+1,k-1,n+1,t);
        }
        else if(a[i]){
            t[k]=a[i];
            stack[n]='i';
            doit(i+1,j,k+1,n+1,t);
        }
    }
}
int main()
{
    char t[160];

    while(scanf("%s%s",a,b)!=EOF){
        printf("[\n");
        doit(0,0,0,0,t);
        printf("]\n");
    }

    return 0;   /* NZEC */
}

/* //2514795 2007-07-11 14:37:06 Accepted 1004 C 00:00.00 2984K わたし */
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2514839 2007-07-11 14:53:01 Accepted 1004 C 00:00.00 392K わたし */

// 2012-09-07 02:54:30 | Accepted | 1004 | C | 0 | 160 | watashi | Source
