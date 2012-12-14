#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,l;
	char ch[88]="o";
	double p;

	while(scanf("%s",ch+1),strcmp(ch+1,"#")){
		l=strlen(ch+1);
		p=0;
		for(i=1;i<=l;i++){
			switch(ch[i]){
			case '.':break;
			case '_':p+=100.0/l;break;
			case '/':
				j=i;while(ch[--j]=='_');
				switch(ch[j]){
				case 'o':case '.':break;
				case '|':case '\\':p+=100.0/l;break;
				}
				break;
			case '\\':
				j=i;while(ch[++j]=='_');
				switch(ch[j]){
				case '\0':case '.':break;
				case '|':case '/':p+=100.0/l;break;
				}
				break;
			case '|':
				j=i;while(ch[--j]=='_');
				switch(ch[j]){
				case 'o':case '.':break;
				case '|':case '\\':p+=50.0/l;break;
				}
				j=i;while(ch[++j]=='_');
				switch(ch[j]){
				case '\0':case '.':break;
				case '|':case '/':p+=50.0/l;break;
				}
				break;
			}
		}
		printf("%d\n",(int)(100-p));
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806315 	3595 	Linear Pachinko 	Accepted 	ANSI C 	0.008 	2011-05-24 11:54:12 */
/*
id => 1174374
pid => 3595
pname => Linear Pachinko
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:03:31
*/
