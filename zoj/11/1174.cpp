#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cstdio>
using namespace std;

int main(void)
{
    int re;
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        set <string> st;
        map <string, string> mp;
        int n;
        char ch, str[10], buf[10];
        scanf("%d ", &n);
        while(n--) {
            gets(str);
            string tmp(str);
            int l = tmp.length();
            int ll = 1 << l;
            for (int mask = 1; mask < ll; mask++) {
                int len = 0;
                for (int bit = 0; bit < l; bit++)
                    if(mask & (1 << bit)) buf[len++] = str[bit];
                buf[len] = '\0';
                string cur(buf);
                if(st.find(cur) == st.end()) {
                    map<string, string>::iterator itr = mp.find(cur);
                    if(itr == mp.end())
                        mp.insert(make_pair(cur, tmp));
                    else if(itr -> second != tmp) {
                        st.insert(cur);
                        mp.erase(itr);
                    }
                }
            }
        }
        string ans = "";
        ch = getchar();
        while(true) {
            if(isupper(ch)) {
                int len = 0;
                do {
                    buf[len++] = ch;
                    ch = getchar();
                }while(isupper(ch));
                buf[len] = '\0';
                map<string, string>::iterator itr = mp.find((string)buf);
                if(itr == mp.end()) {
                    puts("AMBIGUITY");
                    while(ch != '#') ch = getchar();
                    break;
                }
                else ans += itr -> second;
            }
            else if(ch == '#') {
                puts(ans.c_str());
                break;
            }
            else {
                ans += ch;
                ch = getchar();
            }
        }
        if(ri < re) putchar('\n');
    }
    return 0;
}

// Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
// 2748108 2008-02-11 00:04:46 Accepted 1174 C++ 00:00.59 1220K わたし

/*
Rank Submit time Run time Run memory Language User
1 2005-11-24 15:12:44 00:00.32 4824K C++ ant
2 2008-02-11 00:04:46 00:00.59 1220K C++ わたし
3 2006-11-15 16:06:15 00:00.85 3132K C++ Freedom
4 2005-09-14 20:05:57 00:01.00 13584K C++ 风中传说
5 2006-05-25 09:20:04 00:01.22 1376K C++ Output Limit Exceeded
6 2007-07-18 23:38:09 00:01.60 2664K C++ onlook
7 2006-02-03 19:58:06 00:01.65 2664K C++ AC more
8 2006-07-28 17:23:27 00:01.71 3056K C++ Fire
9 2005-12-13 01:09:07 00:01.85 1916K C++ Michaelgs
10 2005-09-22 23:02:50 00:01.89 20376K C++ mast_whu
11 2005-09-25 23:17:37 00:01.90 20372K C++ Robert_Tank2001
12 2007-10-20 13:00:44 00:02.62 5588K C++ gogogo
13 2007-10-20 13:01:13 00:02.62 5592K C++ 一劫蛏田
14 2007-12-01 18:24:26 00:02.75 4320K C++ edifierpeter
15 2007-10-23 15:41:08 00:03.12 10164K C++ chen570
16 2007-10-23 12:13:31 00:03.14 5288K C |Dragon|灬宏
17 2007-10-20 20:12:19 00:03.20 7676K C++ long1
18 2006-03-05 22:13:01 00:03.59 2352K C++ fantastic
19 2006-03-03 20:20:42 00:03.85 2404K C++ zzsheng
20 2005-09-13 13:28:23 00:03.85 5280K C Leave me alone
*/

// 2012-09-07 00:40:06 | Accepted | 1174 | C++ | 310 | 1828 | watashi | Source
