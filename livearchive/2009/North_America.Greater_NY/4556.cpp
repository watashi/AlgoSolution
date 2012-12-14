#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int re;
	char buf[1024];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%s", buf);
		printf("%s", buf);
		scanf("%s", buf);
		if (next_permutation(buf, buf + strlen(buf))) {
			printf(" %s\n", buf);
		} else {
			printf(" BIGGEST\n");
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714982  	2011-01-04 06:15:22 	Accepted	0.002	Minimum	26909	C++	4556 - The Next Permutation
/*
id => 1174215
pid => 4556
pname => The Next Permutation
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:39:59
*/
