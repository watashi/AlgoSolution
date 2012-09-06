/*
输入

  name1;
  hp1,armor1,cool1,amount1,power1
  name2
  hp2,armor2,cool2,amount2,power2
*/
/*题目描述，点点点*/
#include <stdio.h>
int main()
{
    char na[14],nb[14];
    int d[2],h[2],p[2],a[2],c[2];

    while(scanf("%s",na)!=EOF){
        scanf("%d%d%d%d%d",&h[0],&d[0],&c[0],&a[0],&p[0]);
        scanf("%s",nb);
        scanf("%d%d%d%d%d",&h[1],&d[1],&c[1],&a[1],&p[1]);
        p[0]-=d[1];
        p[0]*=a[0];
        if(p[0]<=0) p[0]=1;
        p[1]-=d[0];
        p[1]*=a[1];
        if(p[1]<=0) p[1]=1;
        h[0]=(h[0]+p[1]-1)/p[1]*c[1];
        h[1]=(h[1]+p[0]-1)/p[0]*c[0];
        if(h[0]==h[1]) printf("All Die!\n");
        else printf("%s Survive!\n",(h[0]>h[1])?na:nb);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2661393 2007-10-28 19:58:50 Accepted 1631 C 00:00.01 392K わたし */

// 2012-09-07 03:03:21 | Accepted | 1631 | C | 0 | 160 | watashi | Source
