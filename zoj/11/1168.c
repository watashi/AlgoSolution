#include <stdio.h>
long d[21][21][21];
long w(int a,int b,int c,int A,int B,int C)
{

    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(a > 20 || b > 20 || c > 20)
        return w(20, 20, 20,A,B,C);
    else if(a<A||a==A&&b<B||a==A&&b==B&&c<C)
        return d[a][b][c];
    else if(a < b && b < c)
        return w(a, b, c-1,A,B,C) + w(a, b-1, c-1,A,B,C) - w(a, b-1, c,A,B,C);
    else
        return w(a-1, b, c,A,B,C) + w(a-1, b-1, c,A,B,C) + w(a-1, b, c-1,A,B,C) - w(a-1, b-1, c-1,A,B,C);
}
int main()
{
    int a,b,c;

    for(a=0;a<21;a++)
        for(b=0;b<21;b++)
            for(c=0;c<21;c++)
                d[a][b][c]=w(a,b,c,a,b,c);
    while(scanf("%d%d%d",&a,&b,&c),a!=-1||b!=-1||c!=-1){
        printf("w(%d, %d, %d) = %ld\n",a,b,c,w(a,b,c,20,20,21));
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2500297 2007-06-22 19:14:33 Accepted 1168 C 00:00.21 424K ¤ï¤¿¤· */

// 2012-09-07 02:57:16 | Accepted | 1168 | C | 70 | 196 | watashi | Source
