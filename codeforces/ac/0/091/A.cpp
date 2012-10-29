#include <cstdio>
#include <cstring>

using namespace std;

int last[26];
int next[10086][26];
char s[1 << 20];

int main() {
	int n, m;

	scanf("%s", s);
	n = strlen(s);
	for (int j = 0; j < 26; ++j) {
		last[j] = -1;
	}
	for (int k = 0; k < 2; ++k) {
		for (int i = n - 1; i >= 0; --i) {
			last[s[i] - 'a'] = i;
			for (int j = 0; j < 26; ++j) {
				next[i][j] = last[j];
			}
		}
		for (int j = 0; j < 26; ++j) {
			next[n][j] = next[0][j];
		}
	}

	scanf("%s", s);
	n = strlen(s);
	m = 1;
	for (int i = 0, j = 0; i < n; ++i) {
		int k = next[j][s[i] - 'a'];
		if (k == -1) {
			m = -1;
			break;
		} else if (k < j) {
			++m;
		}
		j = k + 1;
	}
	printf("%d\n", m);

	return 0;
}

