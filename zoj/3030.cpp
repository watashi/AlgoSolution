#include <algorithm> // auto fix CE
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<pair<int, int> > e[2][50005];

int get_id(const char* str)
{
    static map<string, int> mp;
    static map<string, int>::const_iterator it;
    int ret;

    if (str == NULL) {
        mp.clear();
        ret = -1;
    }
    else if ((it = mp.find(str)) != mp.end()) {
        ret = it->second;
    }
    else {
        ret = mp.size();
        mp[str] = ret;
    }

    return ret;
}

int main()
{
    int re, n[2], p[2], a, b, c, d;
    static char buf[1024];

    scanf("%d", &re);
    while (re--) {
        (void)get_id(NULL);
        for (int i = 0; i < 2; i++) {
            scanf("%d%d", &n[i], &p[i]);
            for (int j = 0; j < n[i]; j++) {
                e[i][j].clear();
            }
            scanf("%d", &d);
            while (d--) {
                scanf("%d%s%d", &a, buf, &b);
                e[i][a].push_back(make_pair(get_id(buf), b));
            }
            for (int j = 0; j < n[i]; j++) {
                sort(e[i][j].begin(), e[i][j].end());
            }
        }

        pair<int, int> src, cur, tar = make_pair(p[0], p[1]);
        set<pair<int, int> > st;
        queue<pair<int, int> > q;
        vector<pair<int, int> >::const_iterator p;

        st.insert(make_pair(0, 0));
        q.push(make_pair(0, 0));
        d = 0;
        while (!q.empty() && st.count(tar) == 0) {
            c = q.size();
            ++d;
            while (c--) {
                src = q.front();
                q.pop();
                p = e[1][src.second].begin();
                for (vector<pair<int, int> >::const_iterator i = e[0][src.first].begin(); i != e[0][src.first].end(); ++i) {
                    while (p != e[1][src.second].end() && p->first < i->first) {
                        ++p;
                    }
                    if (p == e[1][src.second].end()) {
                        break;
                    }
                    if (p->first == i->first) {
                        cur = make_pair(i->second, p->second);
                        if (st.count(cur) == 0) {
                            st.insert(cur);
                            q.push(cur);
                            if (cur == tar) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", q.empty() ? -1 : d);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3049218   2008-08-24 18:49:47     Accepted    3030    C++     00:03.83    12112K  watashi@Zodiac

// 2012-09-07 13:37:36 | Accepted | 3030 | C++ | 1980 | 15212 | watashi | Source
