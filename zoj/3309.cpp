#include <set>
#include <list>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

char buf[65536];
set<string> st;
list<string> lst;

void gaoAdd(const string& str) {
        lst.push_front(str);
        st.insert(str);
}

void gaoDel(const string& str) {
        st.erase(str);
}

void gaoSearch() {
        set<string> post;
        list<string>::iterator it = lst.begin();
        while (post.size() < 100 && it != lst.end()) {
                if (post.find(*it) == post.end()) {
                        if (st.find(*it) != st.end()) {
                                fputs(it->c_str(), stdout);
                                post.insert(*it);
                                ++it;
                        } else {
                                it = lst.erase(it);
                        }
                } else {
                        ++it;
                }
        }
        fputs("###\n", stdout);
}

int main() {
        int n;

        while (scanf("%d", &n) != EOF) {
                fgets(buf, sizeof(buf), stdin);
                st.clear();
                lst.clear();
                for (int i = 0; i < n; ++i) {
                        fgets(buf, sizeof(buf), stdin);
                        switch (buf[0]) {
                        case 'n': gaoAdd(buf + 4); break;
                        case 'r': gaoAdd(buf + 6); break;
                        case 't': gaoDel(buf + 4); break;
                        case 's': gaoSearch(); break;
                        }
                }
                fputs("\n", stdout);
        }

        return 0;
}

// Run ID       Submit Time     Judge Status    Problem ID      Language  Run Time(ms)          Run Memory(KB)          User Name       Admin
// 539  2009-07-09 21:59:57     Accepted        1055    C++     410     2488 liehuochongsheng   Source

// 2012-09-07 15:46:31 | Accepted | 3309 | C++ | 270 | 2488 | watashi | Source
