#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

bool ok[26][26];
char s[MAXN], t[26];
int last[26];

int main() {
    int n, m;

    scanf("%s%d", s, &m);
    fill(ok[0], ok[26], true);
    for (int i = 0; i < m; ++i) {
        scanf("%s", t);
        ok[t[0] - 'a'][t[1] - 'a'] = ok[t[1] - 'a'][t[0] - 'a'] = false;
    }
    fill(last, last + 26, 0);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a', d = 0;
        for (int j = 0; j < 26; ++j) {
            if (last[j] >= d && ok[j][c]) {
                d = last[j] + 1;
            }
        }
        last[c] = max(d, 1);
    }
    printf("%d\n", n - *max_element(last, last + 26));

    return 0;
}

