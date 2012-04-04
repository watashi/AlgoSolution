#include <cstdio>

int main() {
	int x, y;

	scanf("%d%d", &x, &y);
	while (true) {
		if (x >= 2 && y >= 2) {
			x -= 2;
			y -= 2;
		} else if (x >= 1 && y >= 12) {
			x -= 1;
			y -= 12;
		} else if (y >= 22) {
			y -= 22;
		} else {
			puts("Hanako");
			break;
		}
		if (y >= 22) {
			y -= 22;
		} else if (x >= 1 && y >= 12) {
			x -= 1;
			y -= 12;
		} else if (x >= 2 && y >= 2) {
			x -= 2;
			y -= 2;
		} else {
			puts("Ciel");
			break;
		}
	}

	return 0;
}

