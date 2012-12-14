#include <math.h>
#include <stdio.h>
double p[3][2];
double a[3],aa[3],x[3];
const char *lc[4]={"Scalene","Isosceles","Equilateral","Equilateral"};
const char *ac[3]={"Obtuse","Right","Acute"};
int zero(double x)
{
	return fabs(x)<0.01;
}
int right(double x)
{
	if(x<88) return 1;
	else if(x>92) return -1;
	else return 0;
}
double calc(int i,int j)
{
	double x=p[i][0]-p[j][0],y=p[i][1]-p[j][1];

	return x*x+y*y;
}
int main()
{
	int length,angle;

	while(scanf("%lf%lf%lf%lf%lf%lf",&p[0][0],&p[0][1],&p[1][0],&p[1][1],&p[2][0],&p[2][1])==6){
		aa[0]=calc(1,2);a[0]=sqrt(aa[0]);
		aa[1]=calc(0,2);a[1]=sqrt(aa[1]);
		aa[2]=calc(0,1);a[2]=sqrt(aa[2]);
		if(zero(a[1]+a[2]-a[0])||zero(a[0]+a[2]-a[1])||zero(a[0]+a[1]-a[2])){
			printf("Not a Triangle\n");
			continue;
		}
		length=0;
		if(zero(a[0]-a[1])) length++;
		if(zero(a[0]-a[2])) length++;
		if(zero(a[1]-a[2])) length++;
		x[0]=acos((aa[1]+aa[2]-aa[0])/(2*a[1]*a[2]))/acos(0.0)*90;
		x[1]=acos((aa[0]+aa[2]-aa[1])/(2*a[0]*a[2]))/acos(0.0)*90;
		x[2]=acos((aa[0]+aa[1]-aa[2])/(2*a[0]*a[1]))/acos(0.0)*90;
		angle=right(x[0])*right(x[1])*right(x[2])+1;
		printf("%s %s\n",lc[length],ac[angle]);
	}
	printf("End of Output\n");

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806267 	2837 	Three Sides Make a Triangle 	Accepted 	ANSI C 	0.012 	2011-05-24 11:10:58 */
/*
id => 1174349
pid => 2837
pname => Three Sides Make a Triangle
status => Accepted
lang => ANSI C
time => 0.012
date => 2012-12-14 18:00:37
*/
