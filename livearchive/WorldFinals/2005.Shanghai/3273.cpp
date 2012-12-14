#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);
const double begin = (5 * 60 + 37) * 60;
const double end = (18 * 60 + 17) * 60;

void dump(double r) {
	int off = (int)(begin + (end - begin) * r + 1e-8);
//	printf("%lf => %d\n", r, off);
	printf("%02d:%02d:%02d", off / 3600, off / 60 % 60, off % 60);
}

const int MAXN = 128;

int main() {
	int ri = 0, n, w, h, a[MAXN], d[MAXN], r, c;
	double dx, dy, dz;

	while (scanf("%d", &n) != EOF && n > 0) {
		scanf("%d%d", &w, &h);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (i < n) {
				scanf("%d", &d[i]);
			}
		}
		if (ri > 0) {
			puts("");
		}
		printf("Apartment Complex: %d\n", ++ri);
		while (scanf("%d", &r) != EOF && r != 0) {
			printf("\nApartment %d: ", r);
			c = r / 100;
			r %= 100;
			if (r < 1 || r > n || c < 1 || c > a[r]) {
				puts("Does not exist");
				continue;
			}
			
			dz = dx = 0;
			for (int i = r - 1; i >= 1; --i) {
				dx += d[i];
				dy = (a[i] - c + 1) * h;
				dz = max(dz, dy / dx);
				dx += w;
			}
	//		printf("dz = %lf; ", dz);
			dump(atan(dz) / PI);
			printf(" - ");

			dz = dx = 0;
			for (int i = r + 1; i <= n; ++i) {
				dx += d[i - 1];
				dy = (a[i] - c + 1) * h;
				dz = max(dz, dy / dx);
				dx += w;
			}
			dump(1 - atan(dz) / PI);
			puts("");
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//725275  	2011-01-24 17:01:54 	Accepted	0.187	408	26909	C++	3273 - Lots of Sunlight

/*
id => 1174322
pid => 3273
pname => Lots of Sunlight
status => Accepted
lang => C++
time => 0.132
date => 2012-12-14 17:54:19
*/
