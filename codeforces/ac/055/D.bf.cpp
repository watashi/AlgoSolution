#include <cstdio>

int main() {
	int s = 1;
	
	for (int i = 1; i < 10101; ++i) {
		int t = i;
		bool f = true;
		while (t > 0) {
			if (t % 10 != 0) {
				if (i % (t % 10) != 0) {
					f = false;
				}
			}
			t /= 10;
		}
		if (f) {
			++s;
		} else {
		}
		printf("%d\n", s);
	}

	return 0;
}

