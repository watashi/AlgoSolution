#include <cstdio>

int main() {
	int x1, y1, z1, x2, y2, z2;

	scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
	puts(x1 != x2 && y1 != y2 && z1 != z2 ? "NO" : "YES");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//396354 	Apr 19, 2011 3:33:42 PM 	watashi 	39D - Cubical Planet 	GNU C++ 	Accepted 	30 ms 	1300 KB 
