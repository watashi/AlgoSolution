/*quicksort & search_bin*/
#include <stdio.h>
#include <string.h>
typedef struct{
    char e[11],w[11];
}DIC;
void quicksort(int l,int r,DIC b[])
{
    int i,j;
    DIC x;

    if(l>=r) return;
    i=l;
    j=r;
    x=b[i];
    while(i!=j){
        while(strcmp(b[j].w,x.w)>0&&j>i) j--;
        if(i<j){
            b[i]=b[j];
            i++;
        }
        while(strcmp(b[i].w,x.w)<0&&j>i) i++;
        if(i<j){
            b[j]=b[i];
            j--;
        }
    }
    b[i]=x;
    quicksort(l,j-1,b);
    quicksort(i+1,r,b);
}
int search_bin(DIC b[],char *p,int n)
{
    int low=0,high=n-1,mid,t;

    while(low<=high){
        mid=(low+high)/2;
        t=strcmp(p,b[mid].w);
        if (t==0) return mid;
        else if (t<0) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main()
{
    int i,n,t;
    DIC b[100005];
    char w[15];

    i=0;
    while((b[i].e[0]=getchar())!='\n'){
        scanf("%s%s",&b[i].e[1],b[i].w);
        getchar();
        i++;
    }
    n=i;
    quicksort(0,n-1,b);
    while(scanf("%s",w)!=EOF){
        t=search_bin(b,w,n);
        if(t==-1) printf("eh\n");
        else printf("%s\n",b[t].e);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2517816 2007-07-14 00:13:01 Accepted 1109 C 00:00.56 2540K ¤ï¤¿¤· */

// 2012-09-07 02:56:09 | Accepted | 1109 | C | 220 | 160 | watashi | Source
