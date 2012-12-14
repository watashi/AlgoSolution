#include <stdio.h>
#include <string.h>
struct record{
	char name[21];
	int w;
}a[11];
int main()
{
	int i,j,k,n,blank=0;

	while(scanf("%s",a[0].name)!=EOF && !strcmp(a[0].name,"START")){
		if(blank) printf("\n");
		else blank=1;
		n=0;
		while(scanf("%s",a[n].name)!=EOF && strcmp(a[n].name,"END")){
			scanf("%d %d",&i,&j);
			a[n++].w=j-i;
		}
		for(i=0;i<n;i++){
			k=i;
			for(j=i+1;j<n;j++)
				if(a[j].w>a[k].w) k=j;
			printf("%s\n",a[k].name);
			if(k!=i) a[k]=a[i];
		}
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806250 	2304 	Does This Make Me Look Fat? 	Accepted 	ANSI C 	0.012 	2011-05-24 10:44:13 */
/*
id => 1174376
pid => 2304
pname => Does This Make Me Look Fat?
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:04:09
*/
