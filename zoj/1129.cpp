#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char buf[1024];

int main(void)
{
    int ri = 0, p, n;

    while(scanf("%d%d ", &p, &n) != EOF && p + n > 0) {
        map<string, int> mp;
        vector<set<int> > ve;
        vector<int> vb;
        mp.insert(make_pair("Erdos, P.", 0));
        ve.push_back(set<int>());
        vb.push_back(-1);
        while(p--) {
            vector<string> vs;
            while(true) {
                int i = 0;
                while((buf[i++] = getchar()) != ',');
                while(buf[i] = getchar()) {
                    if(buf[i] == ',') {
                        buf[i] = '\0';
                        vs.push_back((string)buf);
                        getchar();
                        break;
                    }
                    else if(buf[i] == ':') {
                        buf[i] = '\0';
                        vs.push_back((string)buf);
                        gets(buf);
                        i = -1;
                        break;
                    }
                    ++i;
                }
                if(i == -1) break;
            }
            for (int i = 0; i < vs.size(); i++) {
                map<string, int>::iterator itr = mp.find(vs[i]);
                int ii;
                if(itr == mp.end()) {
                    ii = mp.size();
                    mp.insert(make_pair(vs[i], mp.size()));
                    ve.push_back(set<int>());
                    vb.push_back(-1);
                }
                else ii = itr -> second;
                for (int j = 0; j < i; j++) {
                    int jj = mp[vs[j]];
                    ve[ii].insert(jj);
                    ve[jj].insert(ii);
                }
            }
        }
        queue<int> q;
        vb[0] = 0;
        q.push(0);
        while(!q.empty()) {
            int i = q.front();
            for (set<int>::iterator itr = ve[i].begin(); itr != ve[i].end(); ++itr) {
                int j = *itr;
                if(vb[j] == -1) {
                    vb[j] = vb[i] + 1;
                    q.push(j);
                }
            }
            q.pop();
        }
        printf("Database #%d\n", ++ri);
        while(n--) {
            gets(buf);
            map<string, int>::iterator itr = mp.find((string)buf);
            if(itr == mp.end() || vb[itr -> second] == -1) printf("%s: infinity\n", buf);
            else printf("%s: %d\n", buf, vb[itr -> second]);
        }
        putchar('\n');
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746448 2008-02-08 11:38:00 Accepted 1129 C++ 00:00.27 2536K ¤ï¤¿¤·

// 2012-09-07 00:38:29 | Accepted | 1129 | C++ | 140 | 1636 | watashi | Source
