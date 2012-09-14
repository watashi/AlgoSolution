/*
#include <stdio.h>
int a,b,c;
char aa,bb;
int extended_euclid(int a,int b,int *x,int *y)
{
    int xx,yy,t;

    if(b==0){
        *x=1;
        *y=0;
        return a;
    }
    else{
        t=extended_euclid(b,a%b,&xx,&yy);
        *x=yy;
        *y=xx-(a/b)*yy;
        return t;
    }
}
void doit(int va,int vb,int x,int y)
{
    int t;

    if(x==0&&y==0) return;
    if(va==0){
        printf("fill %c\n",aa);
        doit(a,vb,x-1,y);
    }
    else if(vb==b){
        printf("empty %c\n",bb);
        doit(va,0,x,y-1);
    }
    else{
        printf("pour %c %c\n",aa,bb);
        t=b-vb;
        if(t>va) t=va;
        doit(va-t,vb+t,x,y);
    }
}
int main()
{
    int x,y;
    int t;

    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        if(extended_euclid(a,b,&x,&y)!=1) break;
        x*=c;
        y*=c;
        if(x>=0) {aa='A';bb='B';}
        else {t=x;x=y;y=t;t=a;a=b;b=t;aa='B';bb='A';}
        doit(0,0,x,-y);
        if(aa=='B') printf("success\n");
        else printf("empty B\npour A B\nsuccess\n");
    }
}
*/
/* //Output Limit Exceeded 1005 C 00:00.79 392K */
/*
#include <stdio.h>
int main()
{
    int a,b,c,i,t,x,y,va,vb;
    char aa,bb;

    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        for(i=0;;i++){
            if((c-i*a)%b==0){
                x=i;y=-(c-i*a)/b;
                aa='A';bb='B';
                break;
            }
            if((c-i*b)%a==0){
                x=i;y=-(c-i*b)/a;
                t=a;a=b;b=t;aa='B';bb='A';
                break;
            }
        }
        va=vb=0;
        while(x||y){
            if(va==0){
                printf("fill %c\n",aa);
                va=a;
                x--;
            }
            else if(vb==b){
                if(--y) printf("empty %c\n",bb);
                vb=0;
            }
            else{
                printf("pour %c %c\n",aa,bb);
                t=b-vb;
                if(t>va) t=va;
                va-=t;
                vb+=t;
            }
        }
        if(aa=='B') printf("success\n");
        else printf("empty B\npour A B\nsuccess\n");
    }
}
*/
/* //Output Limit Exceeded */
#include <stdio.h>
int main()
{
    int a,b,c,i,n,t,x,y,va,vb;
    char aa,bb;

    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        x=y=0;
        for(n=2;;n++){
            for(i=1;i<n;i++){
                t=i*a-(n-i)*b;
                if(t==c){
                    x=i;y=n-i;
                    aa='A';bb='B';
                    break;
                }
                if(t==-c){
                    x=n-i;y=i;
                    t=a;a=b;b=t;aa='B';bb='A';
                    break;
                }
            }
            if(x||y) break;
        }
        va=vb=0;
        while(x||y){
            if(va==0){
                printf("fill %c\n",aa);
                va=a;
                x--;
            }
            else if(vb==b){
                if(--y) printf("empty %c\n",bb);
                vb=0;
            }
            else{
                printf("pour %c %c\n",aa,bb);
                t=b-vb;
                if(t>va) t=va;
                va-=t;
                vb+=t;
            }
        }
        if(aa=='B') printf("success\n");
        else printf("empty B\npour A B\nsuccess\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2533069 2007-07-24 13:47:21 Accepted 1005 C 00:00.00 392K ¤ï¤¿¤· */
/* //I can't believe this; */

// 2012-09-07 02:54:36 | Accepted | 1005 | C | 0 | 160 | watashi | Source
