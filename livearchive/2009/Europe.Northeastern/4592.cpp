#include <map>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

template<int R, int P>
inline int hash(const char* p) {
	int ret = 0;
	while (*p != '\0') {
		ret *= R;
		ret += *p;
		ret %= P;
		++p;
	}
	return ret;
}

typedef pair<int, int> PII;
typedef pair<PII, PII> PPP;

inline PII hash2(const char* p) {
	return make_pair(hash<79, 1000003>(p), hash<97, 1000033>(p));
}

const int MAXN = 10086;
const int MAXM = 12;

int main() {
	int n, m;
	char buf[4096], *p, *q;
	static PII h[MAXN][MAXM];

	while (scanf("%d%d", &n, &m) != EOF) {
		fgets(buf, sizeof(buf), stdin);
		for (int i = 0; i < n; ++i) {
			fgets(buf, sizeof(buf), stdin);
			p = strcat(buf, ",");
			for (int j = 0; j < m; ++j) {
				q = strchr(p, ',');
				*q = '\0';
				h[i][j] = hash2(p);
				p = q + 1;
			}
		}
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < j; ++k) {
				map<PPP, int> mp;
				for (int i = 0; i < n; ++i) {
					pair<map<PPP, int>::const_iterator, bool> ret;
					ret = mp.insert(make_pair(PPP(h[i][j], h[i][k]), i));
					if (!ret.second) {
						printf("NO\n%d %d\n%d %d\n", ret.first->second + 1, i + 1, k + 1, j + 1);
						goto NEXT;
					}
				}
			}
		}
		puts("YES");
NEXT:
		continue;
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715023  	2011-01-04 07:22:29 	Accepted	4.039	1816	26909	C++	4592 - Database

/*
id => 1174223
pid => 4592
pname => Database
status => Accepted
lang => C++
time => 0.836
date => 2012-12-14 17:40:50
*/
