#include <stdio.h>
struct matrix{
    long r,c;
}a[26];
long count;
struct matrix mul(struct matrix a,struct matrix b)
{
    struct matrix c;

    if(a.c!=b.r) c.r=c.c=0;
    else{
        c.r=a.r;
        c.c=b.c;
        count+=a.r*a.c*b.c;
    }
    return c;
}
struct matrix doit(char x[])
{
    int i,cc;
    char aa[80],bb[80],*p;

    if(x[1]=='\0') return a[x[0]-'A'];
    i=1;
    cc=0;
    p=aa;
    do{
        *p=x[i];
        if(*p=='(') cc++;
        else if(*p==')') cc--;
        i++;
        p++;
    }while(cc);
    *p='\0';
    cc=0;
    p=bb;
    do{
        *p=x[i];
        if(*p=='(') cc++;
        else if(*p==')') cc--;
        i++;
        p++;
    }while(cc);
    *p='\0';
    return mul(doit(aa),doit(bb));
}
int main()
{
    int i,n;
    char x[256];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",x);
        x[0]-='A';
        scanf("%ld%ld",&a[x[0]].r,&a[x[0]].c);
    }
    gets(x);
    while(gets(x)){
        count=0;
        if(doit(x).r) printf("%ld\n",count);
        else printf("error\n");
    }
}
/**orz myself**/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2530364 2007-07-22 21:20:21 Accepted 1094 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 00:36:33 | Accepted | 1094 | C | 0 | 160 | watashi | Source
