#include <stdio.h>
int a1,b1,c1,a2,b2,c2;
int d,dx,dy;
int main()
{
    int re;
    int x1,y1,x2,y2;

    scanf("%d",&re);
    printf("INTERSECTING LINES OUTPUT\n");
    while(re--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a1=y2-y1;
        b1=x1-x2;
        c1=x1*y2-x2*y1;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a2=y2-y1;
        b2=x1-x2;
        c2=x1*y2-x2*y1;
        d=a1*b2-a2*b1;
        dx=c1*b2-c2*b1;
        dy=a1*c2-a2*c1;
        if(d==0){
            if(dx==0&&dy==0) printf("LINE\n");
            else printf("NONE\n");
        }
        else{
            printf("POINT %.2lf %.2lf\n",1.0*dx/d,1.0*dy/d);
        }
    }
    printf("END OF OUTPUT\n");

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2656087 2007-10-23 22:31:37 Accepted 1280 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 02:58:35 | Accepted | 1280 | C | 0 | 160 | watashi | Source
