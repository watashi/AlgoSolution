#include <stdio.h>
int main()
{
	int ri,repeat,i,j,t,day,k,d[16],a[22][22],b[22][22];

	for(i=0;i<22;i++)
		a[i][0]=a[0][i]=a[i][21]=a[21][i]=b[i][0]=b[0][i]=b[i][21]=b[21][i]=0;
	scanf("%d",&repeat);
	for(ri=0;ri<repeat;ri++){
		if(ri) printf("\n");
		scanf("%d",&day);
		for(i=0;i<16;i++)
			scanf("%d",&d[i]);
		for(i=1;i<=20;i++)
			for(j=1;j<=20;j++)
				scanf("%d",&a[i][j]);
		for(t=0;t<day;t++){
			for(i=1;i<=20;i++)
				for(j=1;j<=20;j++){
					k=a[i][j]+a[i][j-1]+a[i][j+1]+a[i+1][j]+a[i-1][j];
					b[i][j]=a[i][j]+d[k];
					if(b[i][j]>3) b[i][j]=3;
					else if(b[i][j]<0) b[i][j]=0;
				}
			for(i=1;i<=20;i++)
				for(j=1;j<=20;j++)
					a[i][j]=b[i][j];
		}
		for(i=1;i<=20;i++){
			for(j=1;j<=20;j++){
				if(a[i][j]==0) printf(".");
				else if(a[i][j]==1) printf("!");
				else if(a[i][j]==2) printf("X");
				else if(a[i][j]==3) printf("#");
			}
			printf("\n");
		}		
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806233 	2365 	A New Growth Industry 	Accepted 	ANSI C 	0.008 	2011-05-24 10:23:10 */
/*
id => 1174355
pid => 2365
pname => A New Growth Industry
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:01:24
*/
