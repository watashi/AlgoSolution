#include <stdio.h>
#include <string.h>
#define MAXN 65536
char mark[MAXN];
int a, b, c, s;
int main()
{
	int x, And, Or, Xor;
	
	while(scanf("%d%d%d%d", &a, &b, &c, &s) == 4) {
		memset(mark, 0, sizeof(mark));
		And = MAXN - 1;
		Or = 0;
		x = s;
		while(!mark[x]) {
			mark[x] = 1;
			And &= x;
			Or |= x;
			x = (a * x + b) % c;
		}
		Xor = And ^ Or;
		for (x = MAXN >> 1; x; x >>= 1) {
			if(Xor & x) putchar('?');
			else if(Or & x) putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806013 	3849 	Persistent Bits 	Accepted 	C++ 	0.008 	2011-05-23 17:13:50
/*
id => 1174262
pid => 3849
pname => Persistent Bits
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:46:28
*/
