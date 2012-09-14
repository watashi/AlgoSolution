#include <stdio.h>
struct rgb{
    int r;
    int g;
    int b;
};
int main()
{
    int i=0,min,index;
    struct rgb a[16],b;

    while(scanf("%d %d %d",&a[i].r,&a[i].g,&a[i].b),a[i].r>=0&&a[i].g>=0&&a[i].b>=0&&i<16-1)
        i++;
    while(scanf("%d %d %d",&b.r,&b.g,&b.b),b.r>=0&&b.g>=0&&b.b>=0){
        min=3*255*255*255+1;
        for(i=0;i<16;i++)
            if((b.r-a[i].r)*(b.r-a[i].r)+(b.g-a[i].g)*(b.g-a[i].g)+(b.b-a[i].b)*(b.b-a[i].b)<min){
                min=(b.r-a[i].r)*(b.r-a[i].r)+(b.g-a[i].g)*(b.g-a[i].g)+(b.b-a[i].b)*(b.b-a[i].b);
                index=i;
            }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",b.r,b.g,b.b,a[index].r,a[index].g,a[index].b);
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464499 2007-05-26 22:57:51 Accepted 1067 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 02:55:24 | Accepted | 1067 | C | 0 | 160 | watashi | Source
