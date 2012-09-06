/*
int myscanf()
{
    char ch;
    int res=0;


    ch=getchar();
    while(ch!='\n'&&ch!=' '){
        res*=10;
        res+=ch-'0';
        ch=getchar();
    }
    return res;
}
*/
#include <stdio.h>
int main()
{
    int ri,repeat;
    int i,j,k,n;
    int ps[50]={0},ws[50]={0},code[50]={-1};
    /*const int Left1=1,Right2=2,Left0=-1,Right0=0;*/

    scanf("%d",&repeat);
    for(ri=1;ri<=repeat;ri++){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&ps[i]);
            for(j=ps[i-1];j<ps[i];j++)
                code[i+j]=1;
            code[i+j]=2;
        }
        j=0;
        for(i=1;i<=n;i++){
            ws[i]=1;
            while(code[++j]!=2);
            code[j]=0;
            k=j-1;
            while(k>0&&code[k]!=1){
                if(!code[k]) ws[i]++;
                k--;
            }
            code[k]=-1;
            printf("%d",ws[i]);
            if(i==n) printf("\n");
            else printf(" ");
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2499397 2007-06-21 19:34:24 Accepted 1016 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 02:54:42 | Accepted | 1016 | C | 0 | 160 | watashi | Source
