#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string dic[1024], pat;
char buf[128];

int main()
{
    int n, m;
    size_t c;

    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            dic[i] = buf;
            sort(dic[i].begin(), dic[i].end());
        }
        scanf("%s", buf);
        pat = buf;
        c = count(pat.begin(), pat.end(), '_');
        pat.erase(remove(pat.begin(), pat.end(), '_'), pat.end());
        sort(pat.begin(), pat.end());
        m = 0;
        for (int i = 0; i < n; i++) {
            m += (set_intersection(dic[i].begin(), dic[i].end(), pat.begin(), pat.end(), buf) - buf + c >= dic[i].length());
        }
        printf("%d\n", m);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750208   2009-01-28 15:36:04     Accepted    3065    C++     20  180     watashi@Zodiac

// 2012-09-07 01:59:29 | Accepted | 3065 | C++ | 10 | 184 | watashi | Source
