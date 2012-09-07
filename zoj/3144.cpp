#include <cstdio> // auto fix CE
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

struct Rec
{
    int c[26];
    Rec()
    {
        for (int i = 0; i < 26; i++) {
            c[i] = 0;
        }
    }
    Rec& operator+=(const Rec& r)
    {
        for (int i = 0; i < 26; i++) {
            c[i] += r.c[i];
        }

        return *this;
    }
};

inline int format(char ch)
{
    return tolower(ch) - 'a';
}

int main()
{
    int n, m;
    string buf, cur;

    while (cin >> n) {
        vector<Rec> v(n);
        getline(cin, buf);
        for (int i = 0; i < n; i++) {
            getline(cin, buf);
            istringstream iss(buf);
            while (iss >> cur) {
                v[i].c[format(cur[0])] = max(v[i].c[format(cur[0])], (int)cur.length());
            }
        }

        Rec s;
        for (int i = 0; i < n; i++) {
            s += v[i];
        }

        cin >> m;
        getline(cin, buf);
        for (int i = 0; i < m; i++) {
            getline(cin, buf);
            istringstream iss(buf);
            string name1, name2;
            Rec r;
            iss >> name1 >> name2;
            name1[0] = name1[0];
            name2[1] = name2[1];
            while (iss >> cur) {
                r.c[format(cur[0])] = max(r.c[format(cur[0])], (int)cur.length());
            }
            int ans;
            if (r.c[format(name1[0])] > 0 && r.c[format(name2[0])] > 0) {
                ans = max(r.c[format(name1[0])] + s.c[format(name1[0])] + name1.size(), r.c[format(name2[0])] + s.c[format(name2[0])] + name2.size());
            }
            else if (r.c[format(name1[0])] > 0) {
                ans = r.c[format(name1[0])] + s.c[format(name1[0])] + name1.size();
            }
            else if (r.c[format(name2[0])] > 0) {
                ans = r.c[format(name2[0])] + s.c[format(name2[0])] + name2.size();
            }
            else {
                ans = 0;
                for (int i = 0; i < 26; i++) {
                    if (r.c[i] > 0) {
                        ans = max(ans, r.c[i] + s.c[i]);
                    }
                }
                ans += max(name1.length(),  name2.length());
            }
            printf("%d\n", ans + 2);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750186   2009-01-28 15:20:56     Accepted    3144    C++     0   184     watashi@Zodiac

// 2012-09-07 13:37:54 | Accepted | 3144 | C++ | 0 | 188 | watashi | Source
