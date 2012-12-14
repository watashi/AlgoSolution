#include <stdio.h>
const int np=11,p[40]={2,3,5,7,11,13,17,19,23,29,31,37};
int phi[1001];
int main()
{
	int i,j,k;

	phi[0]=phi[1]=1;
	for(i=2;i<=1000;i++){
		k=1;
		for(j=0;p[j]*p[j]<=i;j++)
			if(i%p[j]==0){
				k=i/p[j];
				if(k%p[j]==0) phi[i]=phi[k]*p[j];
				else phi[i]=phi[k]*(p[j]-1);
				k=0;
				break;
			}
		if(k) phi[i]=i-1;
	}
	for(i=1;i<=1000;i++)
		phi[i]+=phi[i]+phi[i-1];
	scanf("%d",&k);
	for(j=1;j<=k;j++){
		scanf("%d",&i);
		printf("%d %d %d\n",j,i,phi[i]);
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805980 	3571 	Visible Lattice Points 	Accepted 	ANSI C 	0.008 	2011-05-23 16:30:35 */
/*
id => 1174350
pid => 3571
pname => Visible Lattice Points
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:00:47
*/
