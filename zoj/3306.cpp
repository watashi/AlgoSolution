#include <cstdio>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

template<int N>
struct Bits {
        int a[N];

        Bits() {
                a[0] = 0;
                for (int i = 0; i < N; ++i) {
                        a[i] = a[i >> 1] + (i & 1);
                }
        }

        int operator()(int i) const {
                return a[i];
        }
};

const int SIZE = 20;
const int BUFSIZE = 32;
const Bits<1 << SIZE> bits;

int best;
char buf[BUFSIZE][BUFSIZE];
int mask[SIZE], cnt[SIZE + 1];

int main() {
        int n, tmp, ans;

        while (scanf("%d", &n) != EOF && (n > 0)) {
                fgets(buf[0], sizeof(buf[0]), stdin);
                for (int i = 0; i < SIZE; ++i) {
                        fgets(buf[i], sizeof(buf[i]), stdin);
                        mask[i] = 0;
                        for (int j = 0; j < SIZE; ++j) {
                                if (buf[i][j] == '#') {
                                        mask[i] |= 1 << j;
                                }
                        }
                }
                ans = 0;
                for (int i = 1; i < (1 << SIZE); ++i) {
                        int m = n - bits(i);
                        if (m > 0 || m <= SIZE) {
                                fill(cnt, cnt + SIZE + 1, 0);
                                for (int j = 0; j < SIZE; ++j) {
                                        ++cnt[bits(i & mask[j])];
                                }
                                tmp = 0;
                                for (int j = SIZE; j > 0 && m > 0; --j) {
                                        if (cnt[j] > 0) {
                                                tmp += j * min(m, cnt[j]);
                                                m -= cnt[j];
                                        }
                                }
                                ans = max(ans, tmp);
                                // sort(cnt, cnt + SIZE, greater<int>());
                                // partial_sort(cnt, cnt + (n - bits(i)), cnt + SIZE, greater<int>());  // -_-b ±ÈsortÂý
                                // ans = max(ans, accumulate(cnt, cnt + (n - bits[i]), 0));
                        }
                }
                printf("%d\n", ans);
        }

        return 0;
}

// Run ID       Submit Time     Judge Status    Problem ID      Language  Run Time(ms)          Run Memory(KB)          User Name       Admin
// 536  2009-07-09 21:16:02     Accepted        1053    C++     2520    4276 liehuochongsheng   Source

// 2012-09-07 15:46:12 | Accepted | 3306 | C++ | 1860 | 4276 | watashi | Source
