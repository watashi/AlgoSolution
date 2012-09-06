/*
odd 2*n-1 n*n
even 2*n n*(n+1)
*/
/*
#include <stdio.h>
#include <math.h>
int main()
{
    long nodd,n,f,t,d;

    while(scanf("%ld%ld",&f,&t)){
        d=t-f;
        if(d<=3) printf("%ld\n",d);
        else{
            nodd=(long)sqrt(d)+1;
            if((nodd-1)*(nodd-1)==d) nodd--;
            n=2*nodd-1;
            if(nodd*(nodd-1)>=d) n--;
            printf("%ld\n",n);
        }
    }
}
*/
/* //TLE */
#include <stdio.h>
int main(){
    long most[32000];
    long i;
    int j,n,x,y,d;
    for (i=0;i<16000;i++){
        most[2*i] = i*(i+1);
        most[2*i+1] = (i+1)*(i+1);
    }
    while(scanf("%d%d",&x,&y)!=EOF){
        d=y-x;
        for(j=0;most[j]<d;j++);
        printf("%d\n",j);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2502213 2007-06-24 23:05:21 Accepted 1871 C 00:00.03 516K ¤ï¤¿¤· */
/*dramatically different in time*/

// 2012-09-07 03:06:02 | Accepted | 1871 | C | 10 | 160 | watashi | Source
