#include <set>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	set<pair<int, int> > from, to;

	from.insert(make_pair(0, 0));
	for (int i = 0; i < 20; ++i) {
		printf("%d\n", from.size());
	//	to.clear();
		to = from;
		for (set<pair<int, int> >::const_iterator it = from.begin(); it != from.end(); ++it) {
			for (int i = 0; i < 8; ++i) {
				to.insert(make_pair(it->first + dx[i], it->second + dy[i]));
			}
		}
		from.swap(to);
	}

	return 0;
}

/*
1
8
33
76
129
196
277
372
481
604
741
892
1057
1236
1429
1636
1857
2092
2341
2604

a(n) = -3 + 4*n + 7*n^2 + 4*Sign[(n - 2)(n - 1)] - Anton Chupin (chupin(AT)icmm.ru), May 14 2006 generating function = (1 + 5*x + 12*x^2 - 8*x^4 + 4*x^5)/(1 - x)^3

==============================

1
9
41
109
205
325
473
649
853
1085
1345
1633
1949
2293
2665
3065
3493
3949
4433
4945

G.f.: (1+5*x+12*x^2-8*x^4+4*x^5)*(1+x)/(1-x)^3;.

a(n)=1-6*n+14*n^2+4*Sign[n(n-1)(n-3)]. - Zak Seidov (zakseidov(AT)yahoo.com), Mar 01 2005 

=========================================


	1, 8, 32, 68, 96, 120, 148, 176, 204, 232, 260, 288, 316, 344, 372, 400, 428, 456, 484, 512, 540, 568, 596, 624, 652, 680, 708, 736, 764, 792, 820, 848, 876, 904, 932, 960, 988, 1016, 1044, 1072, 1100, 1128, 1156

	FORMULA 	

a(n) = 28*n+8, n >= 4.
	MAPLE 	

(1+5*x+12*x^2-8*x^4+4*x^5)*(1+x)/(1-x)^2; 
*/
