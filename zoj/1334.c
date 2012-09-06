#include <stdio.h>
int main()
{
    int i,n,a[8],base0,base;
    char ch[8];
    long x;

    while(scanf("%c",&ch[0])!=EOF){
        for(i=1;i<=6;i++)
            scanf("%c",&ch[i]);
        scanf("%d %d",&base0,&base);
        x=i=0;
        while(ch[i++]==' ');
        for(i--;i<7;i++){
            if(ch[i]>='0'&&ch[i]<='9') x=base0*x+ch[i]-'0';
            else x=base0*x+ch[i]-'A'+10;
        }
        i=0;
        do{
            a[i++]=x%base;
            x/=base;
        }while(i<8&&x);
        n=i;
        if(i==8) printf("  ERROR\n");
        else{
            for(i=6;i>=n;i--)
                printf(" ");
            for(i=n-1;i>=0;i--)
                switch(a[i]){
                case 0:case 1:case 2:case 3:case 4:
                case 5:case 6:case 7:case 8:case 9:
                    printf("%d",a[i]);break;
                case 10:printf("%c",'A');break;
                case 11:printf("%c",'B');break;
                case 12:printf("%c",'C');break;
                case 13:printf("%c",'D');break;
                case 14:printf("%c",'E');break;
                case 15:printf("%c",'F');break;
            }
        printf("\n");
        }
        getchar();
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469478 2007-05-29 12:18:54 Accepted 1334 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 02:59:42 | Accepted | 1334 | C | 0 | 160 | watashi | Source
