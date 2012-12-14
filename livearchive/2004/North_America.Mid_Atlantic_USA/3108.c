#include <stdio.h>
int main()
{
	struct{
		char pst[16];
		float ss;
		int mw,ms;
	}pp[3]={{"Wide Receiver", 4.5, 150, 200 },
			{"Lineman", 6.0, 300, 500 },
			{"Quarterback", 5.0, 200, 300 }},*p=pp;
	float ss;
	int i,iF,mw,ms;

	while(scanf("%f%d%d",&ss,&mw,&ms),ss){
		for(iF=i=0;i<3;i++)
			if((p+i)->ss>=ss&&(p+i)->mw<=mw&&(p+i)->ms<=ms){
				if(iF) printf(" ");
				printf("%s",(p+i)->pst);
				iF=1;
			}
		if(!iF) printf("No positions");
		printf("\n");
	}

	return 0;
}

/* 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806311 	3108 	Filling Out the Team 	Accepted 	ANSI C 	0.004 	2011-05-24 11:48:45 */
/*
id => 1174360
pid => 3108
pname => Filling Out the Team
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:02:01
*/
