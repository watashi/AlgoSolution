#include <map>
#include <cstdio>

using namespace std;

int main() {
	int n, a;
	map<int, int> mp;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		++mp[a];
	}
	a = 0;
	for (const auto& p: mp) {
		a += p.second / 2;
	}
	printf("%d\n", a / 2);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//863264 	Nov 14, 2011 4:27:20 PM 	watashi 	127B - Canvas Frames 	GNU C++0x 	Accepted 	30 ms 	1400 KB 
