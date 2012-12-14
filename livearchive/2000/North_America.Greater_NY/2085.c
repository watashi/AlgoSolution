#include <stdio.h>
int main()
{
	char ch;
	int temp,root,num;

	while(1){
		root=0;
		ch=getchar();
		while(ch>='0'&&ch<='9'){
			temp=ch-'0';
			root+=temp;
			ch=getchar();
		}
		if(root==0) break;
		else
			while(root>=10){
				num=root;
				root=0;
				do{
					temp=num%10;
					root+=temp;
					num/=10;
				}while(num);
			}
		printf("%d\n",root);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805910 	2085 	Digital Roots 	Accepted 	ANSI C 	0.100 	2011-05-23 15:04:07 */
/*
id => 1174344
pid => 2085
pname => Digital Roots
status => Accepted
lang => ANSI C
time => 0.042
date => 2012-12-14 17:59:53
*/
