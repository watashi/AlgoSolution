#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n,d,sur;
	char ch[80],*p=ch,pair[80][2];

	while(gets(ch),ch[0]!='*'){
		n=strlen(ch);
		sur=1;
		for(d=1;d<n&&sur;d++){
			for(i=d;i<n;i++){
				pair[i][0]=ch[i-d];
				pair[i][1]=ch[i];
			}
			for(i=d;i<n&&sur;i++)
				for(j=i+1;j<n;j++)
					if(pair[i][0]==pair[j][0]&&pair[i][1]==pair[j][1]){
						sur=0;
						break;
					}
		}
		if(sur) printf("%s is surprising.\n",ch);
		else printf("%s is NOT surprising.\n",ch);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806317 	3596 	Surprising Strings 	Accepted 	ANSI C 	0.008 	2011-05-24 11:55:22                                                                                   */
/*
id => 1174373
pid => 3596
pname => Surprising Strings
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:03:27
*/
