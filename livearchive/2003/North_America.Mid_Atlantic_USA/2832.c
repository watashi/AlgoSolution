#include <stdio.h>
int main()
{
	/*
	struct prob{
		int sub,time;
	};
	*/
	struct record{
		char name[40];
		/*struct prob p[4];*/
		int sol,time;
	}team[100];
	int sub,time,i,j,n;

	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%s",team[i].name);
			team[i].time=team[i].sol=0;
			for(j=0;j<4;j++){
				scanf("%d%d",&sub,&time);
				if(time){
					team[i].sol++;
					team[i].time+=time+(sub-1)*20;
				}
			}
		}
		j=0;
		for(i=1;i<n;i++){
			if(team[i].sol>team[j].sol) j=i;
			else if(team[i].sol==team[j].sol)
				if(team[i].time<team[j].time) j=i;
		}
		printf("%s %d %d\n",team[j].name,team[j].sol,team[j].time);
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806266 	2832 	A Contesting Decision 	Accepted 	ANSI C 	0.012 	2011-05-24 11:09:10 */

/*
id => 1174348
pid => 2832
pname => A Contesting Decision
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:00:27
*/
