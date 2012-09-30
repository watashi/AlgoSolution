#include <limits>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXL = 180;

struct Atom {
    bool comp, any;
    // unsigned char from, to;
    char from, to;
    bool match(/*unsigned */char ch) const {
        return comp ^ (from <= ch && ch <= to);
    }
};

static vector<Atom> regex;
static int dp[MAXL];

void recomp(const char re[]) {
    int n = strlen(re);
    regex.clear();
    for (int i = 0; i < n; ) {
        Atom a;
        a.comp = a.any = false;

        switch (re[i++]) {
        // case '+': case '*':
        //  throw 1; => no such case
        //  break;
        case '[':
            if (re[i] == '^') {
                a.comp = true;
                ++i;
            }
            if (re[i] == '\\') {
                ++i;
            }
            a.from = re[i++];
            ++i;
            // assert(re[i++] == '-');
            if (re[i] == '\\') {
                ++i;
            }
            a.to = re[i++];
            ++i;
            // assert(re[i++] == ']');
            if (a.from > a.to) {    // between c1 and c2
                swap(a.from, a.to);
            }
            break;
        case '.':
            // a.from = '\0';
            // a.to = '\xff';
            a.from = numeric_limits<char>::min();
            a.to = numeric_limits<char>::max();
            break;
        case '\\':
            ++i;
            // no break;
        default:
            a.from = a.to = re[i - 1];
            break;
        }

        switch (re[i++]) {
        case '+':
            regex.push_back(a);
            // no break;
        case '*':
            a.any = true;
            regex.push_back(a);
            break;
        default:
            regex.push_back(a);
            --i;
            break;
        }

        // assert(i <= n);
    }
}

void reexec(const char str[]) {
    int n = strlen(str);
    for (int i = 0; i <= n; ++i) {
        dp[i] = i;
    }
    for (vector<Atom>::const_reverse_iterator a = regex.rbegin(); a != regex.rend(); ++a) {
        // printf("{%s, [%s(%d)-(%d)]}\n", a->any ? "y" : "n", a->comp ? "^" : "", a->from, a->to);
        if (a->any) {
            for (int i = 0; i <= n; ++i) {
                for (int j = i; j <= n; ++j) {
                    dp[i] = max(dp[i], dp[j]);
                    if (j == n || !a->match(str[j])) {
                        break;
                    }
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                dp[i] = a->match(str[i]) ? dp[i + 1] : -1;
            }
            dp[n] = -1;
        }
        // for (int i = 0; i <= n; ++i) {
        //  printf("%5d", dp[i]);
        // }
        // puts("");
    }
}

int main() {
    int n;
    bool flag;
    char re[MAXL], str[MAXL];

    while (gets(re) != NULL && strcmp(re, "end") != 0) {
        gets(str);
        // 存在非0-127 ASCII字符
        recomp(re);
        reexec(str);
        n = strlen(str);
        flag = false;
        for (int i = 0; !flag && i < n; ++i) {
            if (dp[i] > i) {    // nonempty
                for (int j = 0; j < i; ++j) {
                    putchar(str[j]);
                }
                putchar('(');
                for (int j = i; j < dp[i]; ++j) {
                    putchar(str[j]);
                }
                putchar(')');
                for (int j = dp[i]; j < n; ++j) {
                    putchar(str[j]);
                }
                putchar('\n');
                flag = true;
            }
        }
        if (!flag) {
            puts(str);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//398   2010-07-06 22:59:58     Accepted    1033    C++     20  180     anotherpeg  Source

// 2012-09-30 23:40:41 | Accepted | 1448 | C++ | 0 | 180 | watashi | Source
