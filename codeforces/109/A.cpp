#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n, m;

	scanf("%d", &n);
	m = 0;
	while (n >= 0) {
		if (n % 7 == 0) {
			puts((string(m, '4') + string(n / 7, '7')).c_str());
			return 0;
		}
		++m;
		n -= 4;
	}
	puts("-1");
	return 0;
}

