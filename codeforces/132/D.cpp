#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char buf[1 << 20];
vector<pair<char, int> > v;

int main() {
    int n;

    while (scanf("%s", buf + 3) != EOF) {
        buf[0] = buf[1] = buf[2] = '0';
        n = strlen(buf);
        v.clear();
        for (int i = n - 1, j; i >= 0; i = j - 1) {
            j = i;
            while (buf[j] == '1') {
                --j;
            }
            if (j == i - 1) {
                v.push_back({'+', n - 1 - i});
            } else if (j < i - 1) {
                v.push_back({'-', n - 1 - i});
                buf[j] = '1';
                ++j;
            }
        }
        printf("%d\n", (int)v.size());
        for (auto& p: v) {
            printf("%c2^%d\n", p.first, p.second);
        }
        break;
    }

    return 0;
}

