#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int l, n;
char str[1024];
int len, cnt;
char const * const ans[3] = {
	"NO",
	"YES",
	"NOT UNIQUE"
};

void gao(int p, int l, int n) {
	if (p == len) {
		if (l == ::l && n == ::n) {
			++cnt;
		}
	} else if(str[p] == '0') {
		if (l + 1 <= ::l + 1) {
			gao(p + 1, l + 1, n);
		}
	} else {
		int c = 1;
		for (int i = p + 1; i <= len && l + c <= ::l + 1 && n + c <= ::n + 1; ++i) {
			if (str[i] == '0') {
			   	if (c == 1 || c > 2) {
					gao(i, l + c, n + c);
				}
				if (c == 3) {
					gao(i, l + 2, n + 2);
				}
			}
			c *= 2;
			c += (str[i] == '1');
		}
	}
}

int main(){
	int ri = 0;

	while (scanf("%d%d", &l, &n) != EOF && !(l == 0 && n == 0)) {
		scanf("%s", str);
		len = strlen(str);
		str[len] = '0';
		cnt = 0;
		gao(0, 0, 0);
		if (cnt > 2) {
			cnt = 2;
		}
		printf("Case #%d: %s\n", ++ri, ans[cnt]);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//726005  	2011-01-25 18:46:53 	Accepted	0.043	Minimum	26909	C++	3565 - Bit Compressor
/*
id => 1174027
pid => 3565
pname => Bit Compressor
status => Accepted
lang => C++
time => 0.029
date => 2012-12-14 17:12:17
*/
