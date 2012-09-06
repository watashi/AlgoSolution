/* //CE::2684693.c:4: initializer element is not constant */
/* //CE2::2684699.c:5: initializer element is not constant  2684699.c:6: initializer element is not constant */

#include <math.h>
#include <stdio.h>
const double sqrt3 = 1.7320508075688772935274463415059;
/*const double three=3.0;*/
/*const double sqrt3=sqrt(three);*/

/*double _sqrt3=sqrt(3.0);*/
/*const double sqrt3=_sqrt3;*/

/*double sqrt3=sqrt(3.0);*/
struct point{
    double x,y;
};
void fractal(struct point s,struct point d,int level)
{
    struct point p1,p2,p3,v;

    v.x=d.x-s.x;
    v.y=d.y-s.y;
    p1.x=s.x+v.x/3;
    p1.y=s.y+v.y/3;
    p3.x=d.x-v.x/3;
    p3.y=d.y-v.y/3;
    p2.x=s.x+v.x/2-sqrt3*v.y/6;
    p2.y=s.y+v.y/2+sqrt3*v.x/6;
    if(level==1){
        printf("%.2lf %.2lf\n",p1.x,p1.y);
        printf("%.2lf %.2lf\n",p2.x,p2.y);
        printf("%.2lf %.2lf\n",p3.x,p3.y);
        printf("%.2lf %.2lf\n",d.x,d.y);
    }
    else{
        fractal(s,p1,level-1);
        fractal(p1,p2,level-1);
        fractal(p2,p3,level-1);
        fractal(p3,d,level-1);
    }
}
int main()
{
    struct point s,d;
    int level;

    while(scanf("%d",&level)!=EOF){
        scanf("%lf%lf",&s.x,&s.y);
        scanf("%lf%lf",&d.x,&d.y);
        printf("%.2lf %.2lf\n",s.x,s.y);
        fractal(s,d,level);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684707 2007-11-24 23:19:07 Accepted 1575 C 00:00.15 396K ¤ï¤¿¤· */

// 2012-09-07 03:02:32 | Accepted | 1575 | C | 80 | 160 | watashi | Source
