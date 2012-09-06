#include <math.h>
#include <stdio.h>
int gettime()
{
    int i,h,m,s;
    char str[20];

    scanf("%s",str);
    if(*str=='-') return -1;
    for(i=0;str[i];i++){
        if(str[i]==':') str[i]=' ';
    }
    sscanf(str,"%d%d%d",&h,&m,&s);
    return 3600*h+60*m+s;
}
int main()
{
    int i,n,id,cur;
    double d,t;

    scanf("%d%lf",&n,&d);
    while(scanf("%d",&id)!=EOF){
        printf("%3d: ",id);
        id=1;
        t=0;
        for(i=0;i<n;i++){
            cur=gettime();
            if(cur==-1) t=-999999999.9;
            else t+=(double)cur;
        }
        if(t<0) printf("-\n");
        else{
            t/=d;
            id=(int)(t+0.5);
            printf("%d:%02d min/km\n",id/60,id%60);
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2651962 2007-10-20 17:15:27 Accepted 1963 C 00:00.01 392K ¤ï¤¿¤· */

// 2012-09-07 03:07:31 | Accepted | 1963 | C | 0 | 160 | watashi | Source
