#include <stdio.h>
int main()
{
	static char ascll[128],message[108];
	int i,n,end=0;
	char ch;
	
	for(i=0;i<=127;i++)
		ascll[i]=i;
	for(i=70;i<=90;i++)
		ascll[i]=i-5;
	for(i=65;i<70;i++)
		ascll[i]=i+21;
	for(;;){
		ch='?';
		while(1){
			if(ch=='S'){
				if((ch=getchar())=='T')
				if((ch=getchar())=='A')
				if((ch=getchar())=='R')
				if((ch=getchar())=='T')
				break;
			}
			else if(ch=='E'){
				if((ch=getchar())=='N')
				if((ch=getchar())=='D')
				if((ch=getchar())=='O')
				if((ch=getchar())=='F')
				if((ch=getchar())=='I')
				if((ch=getchar())=='N')
				if((ch=getchar())=='P')
				if((ch=getchar())=='U')
				if((ch=getchar())=='T')
				end=1;
				break;
			}
			else ch=getchar();
		}
		if(end) break;
		while((message[0]=getchar())=='\n');
		for(i=1;i<108;i++){
			message[i]=getchar();
			if(message[i]=='D'&&i>1)
				if(message[i-1]=='N'&&message[i-2]=='E')
					break;				
		}
		n=i;
		for(i=0;i<=n-3;i++)
			if(ascll[message[i]]!='\n') printf("%c",ascll[message[i]]);
		printf("\n");
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806239 	2540 	The Hardest Problem Ever 	Accepted 	ANSI C 	0.008 	2011-05-24 10:31:31 */
/*
id => 1174325
pid => 2540
pname => The Hardest Problem Ever
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:56:59
*/
