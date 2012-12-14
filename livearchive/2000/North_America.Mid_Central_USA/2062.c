#include <stdio.h>
#include <string.h>
int main()
{
	char ch[80],*v="aeiou",*v2[26]={"aa","bb","cc","dd","eee","ff","gg","hh","ii","jj",
		"kk","ll","mm","nn","ooo","pp","qq","rr","ss","tt","uu","vv","ww","xx","yy","zz"};	
	int flag,i,l;

	while(scanf("%s",ch),strcmp(ch,"end")){
		l=strlen(ch);
		flag=0;
		for(i=0;i<5;i++)
			if(strchr(ch,*(v+i))){
				flag=1;
				break;
			}
		if(flag){
			for(i=0;i<26;i++)
				if(strstr(ch,v2[i])){
					flag=0;
					break;
				}
		}
		if(flag){
			for(i=2;i<l;i++)
				if(!strchr(v,ch[i])&&!strchr(v,ch[i-1])&&!strchr(v,ch[i-2])){
					flag=0;
					break;
				}
				else if(strchr(v,ch[i])&&strchr(v,ch[i-1])&&strchr(v,ch[i-2])){
					flag=0;
					break;
				}
		}
		if(flag) printf("<%s> is acceptable.\n",ch);
		else printf("<%s> is not acceptable.\n",ch);
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806252 	2062 	Easier Done than Said? 	Accepted 	ANSI C 	0.012 	2011-05-24 10:47:59 */
/*
id => 1174342
pid => 2062
pname => Easier Done than Said?
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:59:43
*/
