/*
3
10 10 2 Jill
5 3 10 Will
5 5 10 Bill
4
2 4 10 Cam
4 3 7 Sam
8 11 1 Graham
6 2 7 Pam
-1


Sample Output

Bill took clay from Will.
Graham took clay from Cam.



--------------------------------------------------------------------------------
Problem Source: Mid-Central USA 2003
*/
#include <stdio.h>
int main()
{
    struct{
        int x;
        char name[10];
    }stu[10];
    int i,n,a,b,c,sum,min,max;

    while(scanf("%d",&n),n+1){
        sum=0;
        for(i=0;i<n;i++){
            scanf("%d%d%d%s",&a,&b,&c,stu[i].name);
            stu[i].x=a*b*c;
            sum+=stu[i].x;
        }
        sum/=n;
        for(i=0;i<n;i++){
            if(stu[i].x>sum) max=i;
            else if(stu[i].x<sum) min=i;
        }
        printf("%s took clay from %s.\n",stu[max].name,stu[min].name);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2485938 2007-06-09 02:03:46 Accepted 1755 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:04:37 | Accepted | 1755 | C | 0 | 160 | watashi | Source
