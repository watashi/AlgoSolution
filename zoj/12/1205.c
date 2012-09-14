#include <stdio.h>
int main()
{
    char ch;
    int a[201],b[201],sum[102];
    int i,m,n,max;

    while(scanf("%c",&ch)!=EOF){
        i=101;
        do{
            if(ch>='0'&&ch<='9') a[i++]=ch-'0';
            else a[i++]=ch-'a'+10;
        }while((ch=getchar())!='\n');
        m=i;
        i=101;
        while((ch=getchar())!='\n'){
            if(ch>='0'&&ch<='9') b[i++]=ch-'0';
            else b[i++]=ch-'a'+10;
        }
        n=i;
        max=((m>n)?m:n)-101;
        for(i=101-max;i<101;i++){
            a[i]=b[i]=0;
        }
        sum[0]=0;
        for(i=1;i<=max+1;i++){
            sum[i]=a[m-i]+b[n-i];
            if(sum[i-1]>=20){
                sum[i-1]-=20;
                sum[i]+=1;
            }
        }
        if(sum[max+1])
            for(i=max+1;i>=1;i--){
                if(sum[i]>=0&&sum[i]<=9) printf("%c",sum[i]+'0');
                else printf("%c",sum[i]-10+'a');
            }
        else
            for(i=max;i>=1;i--){
                if(sum[i]>=0&&sum[i]<=9) printf("%c",sum[i]+'0');
                else printf("%c",sum[i]-10+'a');
            }
        printf("\n");
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2461227 2007-05-24 22:33:00 Accepted 1205 C 00:00.00 388K わたし */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464509 2007-05-26 23:05:49 Accepted 1205 C 00:00.01 388K わたし */

// 2012-09-07 02:57:46 | Accepted | 1205 | C | 0 | 160 | watashi | Source
