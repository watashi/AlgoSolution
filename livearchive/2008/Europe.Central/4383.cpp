#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;
int t[MAXN];
bool x[MAXN];
pair<int, int> h[MAXN];

int main() {
    int re;
    int n, d, c;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &h[i].first);
            h[i].second = i;
        }
        sort(h + 1, h + n + 1);
        for (int i = 1; i <= d; ++i) {
            scanf("%d", &t[i]);
        }
        fill(x, x + n + 2, false);
        c = 0;
        for (int i = d, j = n; i >= 1; --i) {
            while (j > 0 && h[j].first > t[i]) {
                int k = h[j].second;
                if (x[k - 1] && x[k + 1]) {
                    --c;
                } else if (!x[k - 1] && !x[k + 1]) {
                    ++c;
                }
                x[k] = true;
            //    printf("%d: %d %d %d\n", j, h[j].first, h[j].second, c);
                --j;
            }
            t[i] = c;
        }
        for (int i = 1; i <= d; ++i) {
            printf("%d%c", t[i], i == d ? '\n' : ' ');
        }
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723959  	2011-01-22 17:33:36 	Accepted	2.547	13704	26909	C++	4383 - Skyscrapers

/*
id => 1174232
pid => 4383
pname => Skyscrapers
status => Accepted
lang => C++
time => 0.718
date => 2012-12-14 17:41:58
*/
