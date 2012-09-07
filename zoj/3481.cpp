#include <cmath> // auto fix CE
#include <set>
#include <cmath> // auto fix CE
#include <cerrno>
#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <string>
#include <cmath> // auto fix CE
#include <cassert>
#include <cmath> // auto fix CE
#include <cstring>
#include <cmath> // auto fix CE
#include <algorithm>

using namespace std;

void check(const string& name) {
    for (int i = 0; i < (int)name.length(); ++i) {
        assert(name[i] == '_' || isalnum(name[i]));
    }
    assert(!isdigit(name[0]));
}

set<int> parse(char config[], bool& flag) {
    int ts;
    set<int> ret;
    char* p = config;

    flag = true;
    errno = 0;
    while (*p != '\0') {
        ts = strtol(p, &p, 0);
        assert(errno == 0 && 0 < ts && ts <= 1000);
        ret.insert(ts);
        if (*p == ',') {
            ++p;
            flag = false;
        } else {
            assert(*p == '\0');
        }
    }

    return ret;
}

int main() {
    bool flag;
    int re, col;
    set<int> ts;
    string del, ans, str;
    char buf[4096], tab[4096], end[4096];

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        fgets(buf, sizeof(buf), stdin);
        assert(strlen(buf) <= 1001);
        assert(sscanf(buf, "expand %[0-9,] <<%s", tab, end) == 2);
        check(del = end);
        del += '\n';
        ts = parse(tab, flag);
        ans = "";

        while (fgets(buf, sizeof(buf), stdin) && buf != del) {
            assert(strlen(buf) <= 1001);
            str = "";
            for (int i = 0; buf[i] != '\0'; ++i) {
                if (buf[i] != '\t') {
                    str += buf[i];
                    continue;
                }
                if (flag) {
                    col = (str.length() / *ts.begin() + 1) * *ts.begin();
                } else if (ts.upper_bound(str.length()) == ts.end()) {
                    col = str.length() + 1;
                } else {
                    col = *ts.upper_bound(str.length());
                }
                while ((int)str.length() != col) {
                    str += ' ';
                }
            }
            ans += str;
        }
        puts(ans.c_str());

        fgets(buf, sizeof(buf), stdin);
        assert(strcmp(buf, "\n") == 0);
    }
    assert(fgets(buf, sizeof(buf), stdin) == NULL);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//215   2011-04-03 01:09:25     Accepted    E   C++     20  436     watashi     Source

// 2012-09-07 16:00:28 | Accepted | 3481 | C++ | 10 | 436 | watashi | Source
