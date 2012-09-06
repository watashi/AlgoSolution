#include <stdio.h>
int main()
{
    int i,j,x1,y1,x2,y2,xt,yt,ok;
    char a[12][13]={"????????????","????????????","??","??","??","??","??","??","??","??","????????????","????????????"};

    while(scanf("%s",&a[i=2][2])!=EOF){
        ok=0;
        while(i<9)
            scanf("%s",&a[++i][2]);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1++;
        x2++;
        y1++;
        y2++;
        if(y1==y2&&(x1==x2+1||x2==x1+1)){
            if(x1<x2){xt=x1;x2=x1;x2=xt;}
            if(a[x1][y1-2]==a[x1][y1-1]&&a[x1][y1-1]==a[x2][y1]||
                a[x1][y1-1]==a[x1][y1+1]&&a[x1][y1-1]==a[x2][y1]||
                a[x1][y1+1]==a[x1][y1+2]&&a[x1][y1+1]==a[x2][y1]||
                a[x2][y1-2]==a[x2][y1-1]&&a[x2][y1-1]==a[x1][y1]||
                a[x2][y1-1]==a[x2][y1+1]&&a[x2][y1-1]==a[x1][y1]||
                a[x2][y1+1]==a[x2][y1+2]&&a[x2][y1+1]==a[x1][y1]||
                a[x1+2][y1]==a[x1+1][y1]&&a[x1+1][y1]==a[x2][y1]||
                a[x1+1][y1]==a[x1][y1]&&a[x1][y1]==a[x2][y1]||
                a[x2-1][y1]==a[x1][y1]&&a[x2][y1]==a[x1][y1]||
                a[x2-2][y1]==a[x2-1][y1]&&a[x2-1][y1]==a[x1][y1])   ok=1;
        }
        else if(x1==x2&&(y1==y2+1||y2==y1+1)){
            if(y1<y2){yt=y1;y1=y2;y2=yt;}
            if(a[x1-2][y1]==a[x1-1][y1]&&a[x1-1][y1]==a[x2][y2]||
                a[x1-1][y1]==a[x1+1][y1]&&a[x1+1][y1]==a[x2][y2]||
                a[x1+1][y1]==a[x1+2][y1]&&a[x1+2][y1]==a[x2][y2]||
                a[x2-2][y2]==a[x2-1][y2]&&a[x2-1][y2]==a[x1][y1]||
                a[x2-1][y2]==a[x2+1][y2]&&a[x2+1][y2]==a[x1][y1]||
                a[x2+1][y2]==a[x2+2][y2]&&a[x2+2][y2]==a[x1][y1]||
                a[x1][y1+2]==a[x1][y1+1]&&a[x1][y1+1]==a[x2][y2]||
                a[x1][y1+1]==a[x1][y1]&&a[x1][y1]==a[x2][y2]||
                a[x2][y2-1]==a[x1][y1]&&a[x2][y2]==a[x1][y1]||
                a[x2][y2-2]==a[x2][y2-1]&&a[x2][y2-1]==a[x1][y1])   ok=1;
        }
        if(ok) printf("Ok!\n");
        else printf("Illegal move!\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2490369 2007-06-13 12:12:44 Accepted 1628 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:03:09 | Accepted | 1628 | C | 0 | 160 | watashi | Source
