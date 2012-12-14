#include <stdio.h>
#include <string.h>
#define char2int(x) c2i[x]
#define int2char(x) i2c[x]
char c2i[128],i2c[128];
int main()
{
	int re,i,l,f,bin,bout;
	char in[1000],out[1001];
	int len,num[1000];

	for(i=0;i<10;i++){
		c2i['0'+i]=i;
		i2c[i]='0'+i;
	}
	for(i=0;i<26;i++){
		c2i['A'+i]=i+10;c2i['a'+i]=i+36;
		i2c[i+10]='A'+i;i2c[i+36]='a'+i;
	}
	scanf("%d",&re);
	while(re--){
		scanf("%d%d",&bin,&bout);
		scanf("%s",in);
		len=strlen(in);
		for(i=0;i<len;i++)
			num[i]=char2int(in[i]);
		l=0;
		while(1){
			f=0;
			for(i=0;i<len-1;i++)
				if(num[i]){
					f=1;
					num[i+1]+=(num[i]%bout)*bin;
					num[i]/=bout;
				}
			if(num[i]) f=1;
			out[l++]=int2char(num[i]%bout);
			num[i]/=bout;
			if(f==0) break;
		}
		printf("%d %s\n",bin,in);
		printf("%d ",bout);
		if(l==1) putchar('0'); /**/
		else {l--;while(l--) putchar(out[l]);}
		printf("\n\n");
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805968 	2559 	Number Base Conversion 	Accepted 	ANSI C 	0.008 	2011-05-23 16:13:13 */
/*
id => 1174333
pid => 2559
pname => Number Base Conversion
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:58:37
*/
