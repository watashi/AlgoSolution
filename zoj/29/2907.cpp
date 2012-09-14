#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct SubStr
{
    const char* str;
    int id;
    SubStr(const char *p, int i)
        : str(p), id(i)
    {

    }
    bool operator<(const SubStr& rhs) const
    {
        return strcmp(str, rhs.str) < 0;
    }
};

int get_lcs(const char *a, const char *b, char *c)
{
    int l = 0;

    while (*a != '\0' && *a == *b) {
        *c = *a;
        ++l;
        ++a;
        ++b;
        ++c;
    }
    *c = '\0';

    return l;
}

static char str[4000][256], lcs[256], ans[256];

int main(void)
{
    int n, cmp, len;

    while (scanf("%d", &n) != EOF && n != 0) {
        vector<SubStr> v;

        for (int i = 0; i < n; i++) {
            scanf("%s", str[i]);
            for (char *p = str[i]; *p != '\0'; p++) {
                v.push_back(SubStr(p, i));
            }
        }
        sort(v.begin(), v.end());

        int cc = 0;
        vector<int> c(n, 0);
        vector<SubStr>::const_iterator i = v.begin(), j = v.begin();

        strcpy(ans, "");
        len = 0;
        while (true) {
            //puts("@@");
            //fflush(stdout);
            while (j != v.end()) {
                if (c[j->id] == 0) {
                    ++cc;
                }
                ++c[j->id];
                if (cc == n) {
                    break;
                }
                else {
                    ++j;
                }
            }
            if (j == v.end()) {
                break;
            }
            while (c[i->id] > 1) {
                --c[i->id];
                ++i;
            }
            //printf("%u %u\n", i - v.begin(), j - v.begin());
            //fflush(stdout);
            cmp = get_lcs(i->str, j->str, lcs);
            if (cmp > len) {
                len = cmp;
                strcpy(ans, lcs);
            }
            else if (cmp == len && strcmp(lcs, ans) < 0) {
                strcmp(ans, lcs);
            }
            --cc;
            --c[i->id];
            ++i;
            ++j;
        };

        if (strcmp(ans, "") == 0) {
            puts("IDENTITY LOST");
        }
        else {
            puts(ans);
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3017049 2008-08-01 18:42:13 Accepted 2907 C++ 00:00.53 1908K Re:ReJudge
//

// 2012-09-07 01:46:27 | Accepted | 2907 | C++ | 280 | 2724 | watashi | Source
