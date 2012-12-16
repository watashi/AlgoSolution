#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Postfix
{
	const char *p;
};

bool operator<(const Postfix& lhs, const Postfix& rhs)
{
	return strcmp(lhs.p, rhs.p) < 0;
}

int cnt(const char lhs[], const char rhs[])
{
	int i, j;

	for (i = 0; lhs[i] && lhs[i] == rhs[i]; i++)
		;
	for (j = i; rhs[j]; j++)
		;

	return j - i;
}

char c[5005];
Postfix p[5005];

int main()
{
	int l, ans;

	gets(c);
	l = strlen(c);
	for (int i = 0; i <= l; i++) {
		p[i].p = c + i;
	}
	sort(p, p + l + 1);
	ans = 0;
	for (int i = 1; i <= l; i++) {
		ans += cnt(p[i - 1].p, p[i].p);
	}
	printf("%d\n", ans);
	
	return 0;
}
/*
id => 4678652
date => 15:38:1116 Dec 2012
user => watashi
pname => Bacon’s Cipher
lang => C++
status => Accepted
testid => 
time => 0.14
mem => 132 KB
pid => 1590
*/
