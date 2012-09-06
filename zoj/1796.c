#include <stdio.h>
int main()
{
    int w1,l1,w2,l2,w3,l3;

    while(scanf("%d%d%d%d%d%d",&w1,&l1,&w2,&l2,&w3,&l3),w1+w2+l1+l2)
        printf("Anna's won-loss record is %d-%d.\n",l1+l2-w3,w1+w2-l3);
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2489521 2007-06-12 17:34:15 Accepted 1796 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 01:01:09 | Accepted | 1796 | C | 0 | 160 | watashi | Source
