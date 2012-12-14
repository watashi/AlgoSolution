#include <cmath>
#include <queue>
#include <cstdio>
#include <utility>

using namespace std;

const int MAXN = 128;

double hypot_(double x, double y) {
	return sqrt(x * x + y * y);
}

bool mark[MAXN];
double x[MAXN], y[MAXN], z[MAXN], m[MAXN];

int main() {
	int ri = 0, n, s;
	double ans, sum, tmp;

	while (scanf("%d", &n) != EOF && n > 0) {
		ans = sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf%lf", &x[i], &y[i], &m[i]);
			sum += m[i];
			mark[i] = false;
			z[i] = 1e100;
		}
		
		priority_queue<pair<double, int> > pq;
		z[0] = 0;
		pq.push(make_pair(-z[0], 0));
		while (!pq.empty()) {
			s = pq.top().second;
			if (mark[s]) {
				pq.pop();
				continue;
			}
			pq.pop();
			mark[s] = true;
			ans += z[s] * m[s];
		//	printf("@%d: %lf * %lf\n", s, z[s], m[s]);
			for (int i = 0; i < n; ++i) {
				if (mark[i]) {
					continue;
				}
				tmp = max(z[s], hypot_(x[i] - x[s], y[i] - y[s]));
				if (tmp < z[i]) {
					z[i] = tmp;
					pq.push(make_pair(-z[i], i));
				}				
			}
		}
		printf("Island Group: %d Average %.2lf\n\n", ++ri, ans / sum);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722961  	2011-01-20 15:10:31 	Accepted	0.110	480	26909	C++	2478 - Island Hopping
/*
id => 1174102
pid => 2478
pname => Island Hopping
status => Accepted
lang => C++
time => 0.045
date => 2012-12-14 17:22:25
*/
