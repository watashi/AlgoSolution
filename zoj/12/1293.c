#include <math.h>
#include <stdio.h>
const double SIZE=1024*1024*1.86;
int main()
{
    int ri,size;

    ri=0;
    while(scanf("%d",&size)!=EOF && size){
        size=(size+1)/2;
        size+=(size+1)/2;
        size=(size+61)/62;
        size=(size+29999)/30000;
        printf("File #%d\nJohn needs %d floppies.\n\n",++ri,size);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2656663 2007-10-24 15:04:36 Accepted 1293 C++ 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 00:44:47 | Accepted | 1293 | C | 0 | 160 | watashi | Source
