#include <stdio.h>
int main()
{
    /*
    struct prob{
        int sub,time;
    };
    */
    struct record{
        char name[40];
        /*struct prob p[4];*/
        int sol,time;
    }team[100];
    int sub,time,i,j,n;

    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%s",team[i].name);
            team[i].time=team[i].sol=0;
            for(j=0;j<4;j++){
                scanf("%d%d",&sub,&time);
                if(time){
                    team[i].sol++;
                    team[i].time+=time+(sub-1)*20;
                }
            }
        }
        j=0;
        for(i=1;i<n;i++){
            if(team[i].sol>team[j].sol) j=i;
            else if(team[i].sol==team[j].sol)
                if(team[i].time<team[j].time) j=i;
        }
        printf("%s %d %d\n",team[j].name,team[j].sol,team[j].time);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2502840 2007-06-25 23:52:22 Accepted 1764 C 00:00.00 396K gl hf */

// 2012-09-07 03:04:55 | Accepted | 1764 | C | 0 | 160 | watashi | Source
