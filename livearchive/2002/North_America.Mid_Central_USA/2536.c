#include <stdio.h>
#include <string.h>
#define char2int(x) (x-'@')
char str[15],tmp[6],ans[6];
int len,key;
int power(int x,int y)
{
	int i,res=1;

	for(i=1;i<=y;i++)
		res*=x;
	return res;
}
void dfs(int d,int x)
{
	int i;

	if(d==5){
		if(x==key){
			tmp[5]='\0';
			if(strcmp(ans,"")==0 || strcmp(ans,tmp)<0) strcpy(ans,tmp);
		}
	}
	else{
		for(i=0;i<len;i++){	
			if(str[i]=='\0') continue;
			tmp[d]=str[i];
			str[i]='\0';
			if(d&1) dfs(d+1,x-power(char2int(tmp[d]),d+1));
			else dfs(d+1,x+power(char2int(tmp[d]),d+1));
			str[i]=tmp[d];
		}
	}
}
int main()
{
	while(scanf("%d%s",&key,str)!=EOF && key||strcmp(str,"END")){
		strcpy(ans,"");
		len=strlen(str);
		dfs(0,0);
		if(strcmp(ans,"")) printf("%s\n",ans);
		else printf("no solution\n");
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806245 	2536 	Safecracker 	Accepted 	ANSI C 	0.024 	2011-05-24 10:37:15 */
/*
id => 1174367
pid => 2536
pname => Safecracker
status => Accepted
lang => ANSI C
time => 0.019
date => 2012-12-14 18:02:48
*/
