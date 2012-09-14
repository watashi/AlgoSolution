#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define eps 1e-8
#define xabs(x) (((x)>0)?(x):-(x))
#define zero(x) (xabs(x)<eps)
int main()
{
    char ch,str[20],dir[20];
    const double it=sqrt(2.0)/2;
    double x,y,d;
    int ri=0;

    while(scanf("%[0-9A-Z]",str),strcmp(str,"END")){
        scanf("%c ",&ch);
        x=0;y=0;
        while(1){
            d=atof(str);
            sscanf(str,"%*[0-9]%[NSWE]",dir);
            if(dir[1]==0){
                switch(*dir){
                case 'N':y+=d;break;
                case 'S':y-=d;break;
                case 'W':x-=d;break;
                case 'E':x+=d;break;
                }
            }
            else{
                switch(dir[0]){
                case 'N':y+=d*it;break;
                case 'S':y-=d*it;break;
                }
                switch(dir[1]){
                case 'W':x-=d*it;break;
                case 'E':x+=d*it;break;
                }
            }
            if(ch=='.') break;
            scanf("%[0-9A-Z]%c ",str,&ch);
        }
        if(zero(x)) x=0.000;
        if(zero(y)) y=0.000;
        printf("Map #%d\nThe treasure is located at (%.3lf,%.3lf).\nThe distance to the treasure is %.3lf.\n\n",++ri,x,y,sqrt(x*x+y*y));
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2630503 2007-10-03 19:19:06 Accepted 1247 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 00:43:09 | Accepted | 1247 | C | 0 | 160 | watashi | Source
