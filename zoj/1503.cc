#include <cmath> // auto fix CE
#include <cstdio> // auto fix CE
#include <cmath> // auto fix CE
#include <stdio.h>
#include <cmath> // auto fix CE
#include <cstdio> // auto fix CE
#include <cmath> // auto fix CE
#include <math.h>
long gg[31][31];
long guess(int g,int l)
{
    if(g==0||l==0) return g;
    if(l>=g) l=g-1;
    return gg[g-1][l]+gg[g-1][l-1]+1;
}
int main()
{
    int i,j,g,l,re=0;
    long n;

    for(i=0;i<31;i++)
        for(j=0;j<31;j++)
            gg[i][j]=guess(i,j);
    while(scanf("%d%d",&g,&l),g){
        //n=(g-l)*pow(2,l)+pow(2,l)-1;not middle//but bigger
        printf("Case %d: %ld\n",++re,gg[g][l]);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2495842 2007-06-18 10:04:16 Accepted 1503 C 00:00.00 396K ¤ï¤¿¤·

// 2012-09-07 14:08:40 | Accepted | 1503 | C++ | 0 | 184 | watashi | Source
