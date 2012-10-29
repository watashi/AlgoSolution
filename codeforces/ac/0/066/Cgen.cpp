#include <cstdio>

int main() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			printf("C:\\%d\\%d\\", i, j);
			for (int k = 0; k < 44; ++k) {
				printf("a\\");
			}
			puts("t.txt");
		}
	}

	return 0;
}

