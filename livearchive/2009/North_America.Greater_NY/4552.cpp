#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int re, id, a[12];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &id);
		for (int i = 0; i < 10; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + 10);
		reverse(a, a + 10);
		printf("%d %d\n", id, a[2]);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714978  	2011-01-04 06:07:24 	Accepted	0.004	Minimum	26909	C++	4552 - Nth Largest Value

/*
id => 1174219
pid => 4552
pname => Nth Largest Value
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:40:31
*/
