#include <map>
#include <cstdio>
using namespace std;

map<int, int> mpa, mpb;

inline int state(const int x)
{
	int k = 0, res = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 6; j++) {
			if(x & (1 << k)) {
				res ^= (1 << k);
				if(i >= 1) res ^= (1 << (k - 6));
				if(i <= 3) res ^= (1 << (k + 6));
				if(j >= 1) res ^= (1 << (k - 1));
				if(j <= 4) res ^= (1 << (k + 1));
			}
			++k;
		}
	return res;
}

int main(void)
{
	for (int mask = 0; mask < (1 << 15); mask++) {
		mpa.insert(make_pair(state(mask), mask));
		mpb.insert(make_pair(state(mask << 15), mask << 15));
	}
	int re;
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		int status = 0;
		for (int i = 0; i < 30; i++) {
			int bit;
			scanf("%d", &bit);
			if(bit == 1) status |= 1 << i;
		}
		printf("PUZZLE #%d\n", ri);
		for (map<int, int>::iterator itr = mpa.begin(); itr != mpa.end(); ++itr) {
			int mask = status ^ itr -> first;
			if(mpb.find(mask) != mpb.end()) {
				int ans = mpb[mask] | itr -> second;
				for (int i = 0; i < 30; i++) {
					if(ans & (1 << i)) putchar('1');
					else putchar('0');
					if(i % 6 == 5) putchar('\n');
					else putchar(' ');
				}
				break;
			}
		}
	}
	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805970 	2561 	Extended Lights Out 	Accepted 	C++ 	0.064 	2011-05-23 16:15:51
/*
id => 1174068
pid => 2561
pname => Extended Lights Out
status => Accepted
lang => C++
time => 0.059
date => 2012-12-14 17:18:16
*/
