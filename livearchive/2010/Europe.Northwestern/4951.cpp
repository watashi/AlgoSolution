#include <map>
#include <cstdio>
#include <functional>

using namespace std;

int main() {
	int re, n, x, y, price;
	map<int, int, greater<int> > buy;
	map<int, int> sell;
	char op[80];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		buy.clear();
		sell.clear();
		price = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%s%d shares at %d", op, &x, &y);
			if (op[0] == 'b') {
				buy[y] += x;
			} else if (op[0] == 's') {
				sell[y] += x;
			}
			while (!buy.empty() && !sell.empty() && buy.begin()->first >= sell.begin()->first) {
				price = sell.begin()->first;
				y = min(buy.begin()->second, sell.begin()->second);
				buy.begin()->second -= y;
				if (buy.begin()->second == 0) {
					buy.erase(buy.begin());
				}
				sell.begin()->second -= y;
				if (sell.begin()->second == 0) {
					sell.erase(sell.begin());
				}
			}
			
			if (sell.empty()) {
				printf("-");
			} else {
				printf("%d", sell.begin()->first);
			}
			putchar(' ');
			if (buy.empty()) {
				printf("-");
			} else {
				printf("%d", buy.begin()->first);
			}
			putchar(' ');
			if (price == -1) {
				printf("-");
			} else {
				printf("%d", price);
			}
			putchar('\n');
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881085 	4951 	Stock Prices 	Accepted 	C++ 	0.056 	2011-09-13 09:37:15
/*
id => 1174279
pid => 4951
pname => Stock Prices
status => Accepted
lang => C++
time => 0.022
date => 2012-12-14 17:48:19
*/
