#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const char *c[] = {"", "C", "CC", "CCC"};

const int MAXN = 200200;
pair<int, int> p[MAXN];
int f[MAXN];

int main() {
    int ri = 0;
    int m, n, x, y;
    multiset<int> st;

    while (scanf("%d%d", &m, &n) != EOF && (m > 0 && n > 0)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &p[i].first, &p[i].second);
            f[i] = 0;
        }
        sort(p, p + n);
        for (int i = 0; i < n; ++i) {
            p[n + i] = p[i];
            p[n + i].first += m;
        }
        // C
        st.clear();
        x = 0;
        for (int i = 0; i < n; ++i) {
            x += p[i].second;
            x -= p[i + 1].first - p[i].first;
      //      printf("@%d %d\n", i, x);
            st.insert(x);
        }
        y = 0;
        for (int i = 0; i < n; ++i) {
            if (*st.begin() - y >= 0) {
                f[i] |= 1;
            }
            y += p[i].second;
            y -= p[i + 1].first - p[i].first;
            st.erase(st.find(y));
            if (i < n - 1) {
                x += p[n + i].second;
                x -= p[n + i + 1].first - p[n + i].first;
                st.insert(x);
            }
        }
        // CC
        st.clear();
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            x += p[n + i].second;
            x -= p[n + i].first - p[n + i - 1].first;
            st.insert(x);
       //     printf("@%d %d\n", i, x);
        }
        y = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (*st.begin() - y >= 0) {
                f[i] |= 2;
            }
            y += p[n + i].second;
            y -= p[n + i].first - p[n + i - 1].first;
            st.erase(st.find(y));
            if (i > 0) {
                x += p[i].second;
                x -= p[i].first - p[i - 1].first;
                st.insert(x);
            }
        }
        // CCC
        printf("Case %d:", ++ri);
        for (int i = 0; i < n; ++i) {
            if (f[i] > 0) {
                printf(" %d %s", p[i].first, c[f[i]]);
            }
        }
        puts("");
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727360  	2011-01-29 12:13:35 	Accepted	0.736	5316	26909	C++	4246 - Tanks a Lot

/*
id => 1174294
pid => 4246
pname => Tanks a Lot
status => Accepted
lang => C++
time => 0.236
date => 2012-12-14 17:50:37
*/
