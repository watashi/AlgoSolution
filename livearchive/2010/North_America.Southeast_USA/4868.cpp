#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n, m, x, y, z, ans;
	char s[100];

	while (scanf("%s", s) != EOF && strcmp(s, "0") != 0) {
		n = strlen(s);
		m = (n + 1) / 2;
		sscanf(s, "%d", &x);
		s[m] = '\0';
		sscanf(s, "%d", &y);
		ans = 0x12345678;
		for (int i = y; i <= y + 1; ++i) {
			sprintf(s, "%0*d", m, i);
			if (strlen(s) > m) {
				continue;
			//	sprintf(s, "1%0*d", n, 0);
			//	sscanf(s, "%d", &z);
			} else {
				for (int j = m; j < n; ++j) {
					s[j] = s[n - 1 - j];
				}
				s[n] = '\0';
				sscanf(s, "%d", &z);
			}
		//	printf("[%d] => %d\n", z, z - x);
			if (z >= x) {
				ans = min(ans, z - x);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714864  	2011-01-03 16:49:33 	Accepted	0.020	Minimum	26909	C++	4868 - Palindrometer
/*
id => 1174297
pid => 4868
pname => Palindrometer
status => Accepted
lang => C++
time => 0.019
date => 2012-12-14 17:50:58
*/
