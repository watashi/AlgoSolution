#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

void bfs(int n, int s, const vector<list<int> > & vl, int d[])
{
    int f, t;
    queue<int> q;

    fill(d, d + n, -1);
    d[s] = 0;
    q.push(s);
    while(q.empty() == false) {
        f = q.front();
        q.pop();
        for (list<int>::const_iterator itr = vl[f].begin(); itr != vl[f].end(); itr++) {
            t = *itr;
            if(d[t] == -1) {
                d[t] = d[f] + 1;
                q.push(t);
            }
        }
    }
}

void bfs(int n, const set<int>& st, const vector<list<int> > & vl, int res[])
{
    int *tmp = new int[n];

    fill(res, res + n, 0);
    for (set<int>::const_iterator itr = st.begin(); itr != st.end(); itr++) {
        bfs(n, *itr, vl, tmp);
        for (int i = 0; i < n; i++)
            res[i] = max(res[i], tmp[i]);
    }
}

int main(void)
{
    int t;

    scanf("%d", &t);
    while(t--) {
        int nz, nr, f, t, d, c, ans, pos;
        set<int> st;
        map<int, int> mp;
        map<int, int>::iterator it;
        vector<int> rmp;
        vector<list<int> > vl;

        scanf("%d%d", &nz, &nr);
        for (int i = 0; i < nz; i++) {
            scanf("%d%d", &d, &c);
            it = mp.find(d);
            if(it == mp.end()) {
                mp.insert(make_pair(d, f = mp.size()));
                rmp.push_back(d);
                vl.push_back(list<int>());
            }
            else f = it -> second;
            while(c--) {
                scanf("%d", &d);
                it = mp.find(d);
                if(it == mp.end()) {
                    mp.insert(make_pair(d, t = mp.size()));
                    rmp.push_back(d);
                    vl.push_back(list<int>());
                }
                else t = it -> second;
                vl[f].push_front(t);
            }
        }
        for (int i = 0; i < nr; i++) {
            scanf("%d", &c);
            while(c--) {
                scanf("%d", &d);
                st.insert(mp[d]);
            }
        }

        int *res = new int[vl.size()];
        bfs(mp.size(), st, vl, res);
        ans = numeric_limits<int>::max();
        pos = -1;
        for (int i = 0; i < rmp.size(); i++) {
            if(res[i] < ans) {pos = i; ans = res[i];}
            else if(res[i] == ans) { if(rmp[i] < rmp[pos]) pos = i; }
        }
        printf("%d %d\n", ans + 1, rmp[pos]);
        delete[] res;
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2756980 2008-02-21 18:20:21 Accepted 2913 C++ 00:02.11 3260K ¤ï¤¿¤·

// 2012-09-07 01:46:52 | Accepted | 2913 | C++ | 470 | 2324 | watashi | Source
