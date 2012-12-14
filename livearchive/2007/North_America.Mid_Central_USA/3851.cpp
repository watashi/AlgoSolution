#include <stdio.h>
char usr[32], buf[32];
int log[26];
int main()
{
	int ri = 0;
	int i, j, k;
	char c;

	while(1) {
		for (i = 0; i < 26; i++)
			log[i] = 0;
		while(1) {
			if(scanf("%[A-Z]%c%[a-z]", usr, &c, buf) != 3) return 0;
			k = 0;
			for (i = 0; buf[i]; i++)
				k |= (1 << buf[i] - 'a');
			switch(c) {
			case '+':
				for (i = 0; usr[i]; i++)
					log[usr[i] - 'A'] |= k;
				break;
			case '-':
				for (i = 0; usr[i]; i++)
					log[usr[i] - 'A'] &= ~k;
				break;
			case '=':
				for (i = 0; usr[i]; i++)
					log[usr[i] - 'A'] = k;
				break;
			}
			if(getchar() == '\n') break;
		}
		printf("%d:", ++ri);
		k = 0;
		for (i = 0; i < 26; i++) {
			if(log[i] == 0) continue;
			if(k && log[i] != k) {
				for (j = 0; j < 26; j++)
					if(k & (1 << j)) putchar('a' + j);
			}
			putchar('A' + i);
			k = log[i];
		}
		if(k) {
			for (j = 0; j < 26; j++)
				if(k & (1 << j)) putchar('a' + j);
		}
		putchar('\n');
	}

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806015 	3851 	Electronic Document Security 	Accepted 	C++ 	0.008 	2011-05-23 17:15:19
/*
id => 1174267
pid => 3851
pname => Electronic Document Security
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:46:52
*/
