#include <stdio.h>
#define eps 1e-8
int _random;
/*inline*/ void set_random()
{
    _random=1;
}
/*inline*/ int random()
{
    return _random=(_random*25173+13849)%65536;
}
/*inline*/ int succeed(int r,double p)
{
    return (double)r <=p * 65536.0;
}
/*inline*/ int next(int i)
{
    i++;
    if(i>=9) return 0;
    else return i;
}

struct _data{
    char name[20];
    double hp,sp;
}data[2][9];
char name[2][20];
int no,aa,dd,ii[2],run[2],hit[2],out[2],pos[4],poss[4];
int hitn,hits[1024],runn,runs[1024];

/*inline*/ int sacrifice()
{
    if(pos[1]&&out[aa]==0) return 1;
    else if(pos[2]&&out[aa]<=1) return 1;
    else return 0;
}

/*inline*/ int endgame()
{
    if(no>9&&run[0]!=run[1]) return 1;
    else return 0;
}

/*inline*/ void dos()
{
    out[aa]++;
    if(succeed(random(),data[aa][ii[aa]].sp)){
        if(pos[2]){
            run[aa]++;
            runs[runn++]=poss[2]+aa*10;
        }
        pos[2]=pos[1];
        poss[2]=poss[1];
        pos[1]=pos[0];
        poss[1]=poss[0];
        pos[0]=0;
    }
    ii[aa]=next(ii[aa]);
}

/*inline*/ void doh()
{
    if(succeed(random(),data[aa][ii[aa]].hp)){
        hit[aa]++;
        hits[hitn++]=ii[aa]+aa*10;
        if(pos[2]){
            run[aa]++;
            runs[runn++]=poss[2]+aa*10;
        }
        pos[2]=pos[1];
        poss[2]=poss[1];
        pos[1]=pos[0];
        poss[1]=poss[0];
        pos[0]=1;
        poss[0]=ii[aa];
    }
    else{
        out[aa]++;
    }
    ii[aa]=next(ii[aa]);
}

int main()
{
    int kase;
    int i,ri,re;

    /*set_random();//555555555*/
    scanf("%d", &kase);
    while (kase--) {
        scanf("%d",&re);
        for(ri=1;ri<=re;ri++){
            set_random();/**/
            if(ri>1) printf("============================================================\n");
            scanf("%s",name[0]);
            for(i=0;i<9;i++)
                scanf("%s%lf%lf",data[0][i].name,&data[0][i].hp,&data[0][i].sp);
            scanf("%s",name[1]);
            for(i=0;i<9;i++)
                scanf("%s%lf%lf",data[1][i].name,&data[1][i].hp,&data[1][i].sp);
            printf("Game %d: %s vs. %s\n",ri,name[0],name[1]);
            ii[0]=ii[1]=0;
            run[0]=run[1]=0;
            hit[0]=hit[1]=0;
            no=1;
            while(!endgame()){
                hitn=runn=0;
                out[0]=0;
                aa=0;dd=1;
                pos[0]=pos[1]=pos[2]=0;
                while(out[0]<3){
                    if(sacrifice()) dos();
                    else doh();
                }
                if(no!=9||run[0]>=run[1]){
                    out[1]=0;
                    aa=1;dd=0;
                    pos[0]=pos[1]=pos[2]=0;
                    while(out[1]<3){
                        if(sacrifice()) dos();
                        else doh();
                    }
                }
                printf("\nInning %d:\n",no++);
                printf("Hits:\n");
                if(!hitn) printf("  none\n");
                for(i=0;i<hitn;i++){
                    if(hits[i]>=10) printf("  %15s %15s\n",data[1][hits[i]-10].name,name[1]);
                    else printf("  %15s %15s\n",data[0][hits[i]].name,name[0]);
                }
                printf("\n");
                printf("Runs:\n");
                if(!runn) printf("  none\n");
                for(i=0;i<runn;i++){
                    if(runs[i]>=10) printf("  %15s %15s\n",data[1][runs[i]-10].name,name[1]);
                    else printf("  %15s %15s\n",data[0][runs[i]].name,name[0]);
                }
            }
            printf("\nEnd of Game:\n");
            printf("  %15s %d runs, %d hits\n",name[0],run[0],hit[0]);
            printf("  %15s %d runs, %d hits\n",name[1],run[1],hit[1]);
        }
        if(kase) printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2717870 2008-01-01 21:34:59 Accepted 2890 C 00:00.02 408K わたし */


/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //59 2007-12-26 20:41:23 Accepted 1015 C 00:00:00 396K わたし */

// 2012-09-07 03:14:38 | Accepted | 2890 | C | 0 | 168 | watashi | Source
