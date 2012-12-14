#include <stdio.h>
#include <string.h>
void doit(char *a,char *b,int l,int m)
{
	int i,c[62];

	c[l]=c[l-1]=0;
	for(i=l-1;i;i--){
		c[i-1]=0;
		c[i]+=(a[i]-'0')*m;
		c[i-1]+=c[i]/10;
		c[i]%=10;
	}
	c[0]+=(a[0]-'0')*m;
	if(c[0]>10) b[0]='o';
	else{
		for(i=0;i<l;i++)
			b[i]=c[i]+'0';
	}
	b[l]=0;
}
int main()
{
	char a[61],b[66],str[121];
	int i,l;

	while(gets(a)){
		l=strlen(a);
		strcpy(str,a);
		strcat(str,a);		
		for(i=1;i<=l;i++){
			doit(a,b,l,i);
			if(!strstr(str,b)) break;
		}
		if(i>l) printf("%s is cyclic\n",a);
		else printf("%s is not cyclic\n",a);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805906 	2287 	Round and Round We Go 	Accepted 	ANSI C 	0.008 	2011-05-23 14:59:44
/*
id => 1174046
pid => 2287
pname => Round and Round We Go
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:15:10
*/
