#include <stdio.h>
void f_p(int n,int *pa,int *pb)
{
    int i,j;

    for(j=1;j<=n;j++){
        for(i=1;*(pa+i)!=j;i++)
            if(*(pa+i)>j) (*(pb+j))++;
    }
}
void f_i(int n,int *pa,int *pb)
{
    int i,j;

    *(pb+n+1)=0;
    for(i=1;i<=n;i++){
        for(j=1;*(pa+i)+1;j++)/**/
            if(*(pb+j)==0) (*(pa+i))--;
        *(pb+j-1)=i;
    }
}
int main()
{
    int i,n,a[52],b[52],*pa=&a[0],*pb=&b[0];
    char ch;

    while(scanf("%d",&n),n){
        getchar();
        ch=getchar();
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=0;
        }
        switch(ch){
        case 'P':f_p(n,pa,pb);break;
        case 'I':f_i(n,pa,pb);break;
        }
        for(i=1;i<n;i++)
            printf("%d ",b[i]);
        printf("%d\n",b[n]);
    }
}
/*DONE*/
/* //2461391 2007-05-25 00:21:08 Accepted 1201 C 00:00.00 388K わたし */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464507 2007-05-26 23:04:40 Accepted 1201 C 00:00.01 2984K わたし */

// 2012-09-07 00:41:25 | Accepted | 1201 | C | 0 | 160 | watashi | Source
