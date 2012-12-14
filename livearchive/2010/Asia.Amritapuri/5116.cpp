#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long m;
vector<int> v, p;

void gao(int n, int i, long long k) {
	v.push_back(k);
	for (int j = i; p[j] <= n; ++j) {
		gao(n - p[j], j, (k * p[j]) % m);
	}
}

int main() {
	int re, n;

	for (int i = 2; i < 100; ++i) {
		bool f = true;
		for (int j = 2; j * j <= i; ++j) {
			f &= i % j != 0;
		}
		if (f) {
			p.push_back(i);
		}
	}
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%lld", &n, &m);
		v.clear();
		gao(n, 0, 1);
		sort(v.begin(), v.end());
		printf("%d\n", unique(v.begin(), v.end()) - v.begin());
	}
	
	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716588  	2011-01-07 11:01:54 	Accepted	0.301	720	26909	C++	5116 - Dividing Stones

/*
id => 1174189
pid => 5116
pname => Dividing Stones
status => Accepted
lang => C++
time => 0.119
date => 2012-12-14 17:35:42
*/
