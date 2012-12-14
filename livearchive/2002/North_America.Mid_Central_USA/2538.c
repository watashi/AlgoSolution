#include <stdio.h>
int main()
{
	int i,j,n,n0,count;
	char ch[53];
	
	while(scanf("%d ",&n),n){
		n0=n;
		n=count=i=0;
		while(ch[i]=getchar(),ch[i]!='\n'){
			for(j=0;j<i;j++){
				if(ch[i]==ch[j]){
					n--;
					break;
				}
			}
			if(i==j) n++;
			if(n>n0){
				count++;
				n--;
				ch[i]=' ';
			}
			i++;
		}
		if(count==0) printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n",count/2);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806246 	2538 	Tanning Salon 	Accepted 	ANSI C 	0.004 	2011-05-24 10:39:06 */
/*
id => 1174365
pid => 2538
pname => Tanning Salon
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:02:35
*/
