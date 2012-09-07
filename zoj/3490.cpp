#include <cctype>
#include <cstdio>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

char next[128], carry[128];

void init() {
    for (int i = 0; i < 128; ++i) {
        next[i] = i + 1;
        carry[i] = false;
    }
    next['9'] = '0';
    carry['9'] = true;
    next['Z'] = 'A';
    carry['Z'] = true;
    next['z'] = 'a';
    carry['z'] = true;
}

string succ(string s) {
    int last = '.';
    for (string::reverse_iterator i = s.rbegin(); i != s.rend(); ++i) {
        if (isalnum(*i)) {
            last = *i;
            *i = next[last];
            if (!carry[last]) {
                return s;
            }
        }
    }
    if (last == '.') {
        *s.rbegin() = next[(int)*s.rbegin()];
    } else {
        s.insert(s.begin() + s.find(next[last]),
            isdigit(last) ? '1' : isupper(last) ? 'A' : 'a');
    }
    return s;
}

int main() {
    int re, n;
    string s;
    char buf[4096];

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%s%d", buf, &n) == 2);
        s = buf;
        assert((int)s.length() <= 100 && 1 <= n && n <= 100);
        for (int i = 0; i < (int)s.length(); ++i) {
            assert(' ' < s[i] && s[i] <= 'z');
        }
        for (int i = 0; i < n; ++i) {
            s = succ(s);
            puts(s.c_str());
        }
        puts("");
    }
    assert(scanf("%s", buf) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//469   2011-04-15 01:44:50     Accepted    D   C++     40  180     watashi     Source

// 2012-09-07 16:01:28 | Accepted | 3490 | C++ | 30 | 180 | watashi | Source
