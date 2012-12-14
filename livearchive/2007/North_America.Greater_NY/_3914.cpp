#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void flip(int s[], int p)
{
	for (int i = 0; i < p; i++)
		s[i] = -s[i];
	reverse(s, s + p);
}

int s[32];
int k, ans[128];

int main(void)
{
	int re;
	int n;
	
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ri++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		k = 0;
		for (int i = n; i > 1; i--) {
			int p = 0;
			for (int j = 0; j < i; j++) {
				if (abs(s[j]) == i) {
					p = j + 1;
					break;
				}
			}
			if (p == i && s[p - 1] > 0)
				continue;
			if (p != 1) {
				ans[k++] = p;
				flip(s, p);
			}
			if (s[0] > 0) {
				ans[k++] = 1;
				flip(s, 1);
			}
			ans[k++] = i;
			flip(s, i);
		}
		if (s[0] < 0) {
			ans[k++] = 1;
			flip(s, 1);
		}

		printf("%d %d", ri, k);
		for (int i = 0; i < k; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}

	return 0;
}

/*
id => 1174187
pid => 3914
pname => Flipping Burned Pancakes
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:35:31
*/
