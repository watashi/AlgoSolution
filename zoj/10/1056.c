#include <stdio.h>
struct xy{
    int x,y;
};
int raninto(struct xy *p)
{
    int i;

    for(i=-19;i;i++)/*do not include tail*/
        if((p+i)->x==p->x&&(p+i)->y==p->y) break;
    if(i<0) return 1;
    else return 0;
}
int main()
{
    struct xy *p,a[135]={{25,11},{25,12},{25,13},{25,14},{25,15},{25,16},{25,17},{25,18},{25,19},{25,20},
            {25,21},{25,22},{25,23},{25,24},{25,25},{25,26},{25,27},{25,28},{25,29},{25,30}};
    int i,n,ranoff;
    char str[100];

    while(scanf("%d",&n),n){
        scanf("%s",str);
        ranoff=0;
        p=a+20;
        for(i=0;i<n;i++,p++){
            *p=*(p-1);
            switch(str[i]){
            case 'N':p->x++;break;
            case 'S':p->x--;break;
            case 'W':p->y--;break;
            case 'E':p->y++;break;
            }
            if(p->x<1||p->y<1||p->x>50||p->y>50) {ranoff=1;break;}
            else if(raninto(p)) break;
        }
        if(i>=n) printf("The worm successfully made all %d moves.\n",n);
        else if(ranoff) printf("The worm ran off the board on move %d.\n",i+1);
        else printf("The worm ran into itself on move %d.\n",i+1);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2497986 2007-06-20 14:10:34 Accepted 1056 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 00:34:44 | Accepted | 1056 | C | 0 | 160 | watashi | Source
