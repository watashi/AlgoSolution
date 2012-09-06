// var can not be time(can be timed) CE
#include <map>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <vector <pair <int, int> > > Stop;
typedef vector <pair <vector <int>, vector <pair <int, int> > > > Route;

int timed[2][1001];
map <string, int> mp;
Stop stop;
Route route;

void bfs(int begin, int start, int timed[], const Stop& stop, const Route& route)
{
    int n = stop.size();
    bool *mark = new bool[n];
    fill(mark, mark + n, false);
    fill(timed, timed + n, numeric_limits<int>::max());
    timed[begin] = start;
    for (int loop = 0; loop < n; loop++) {
        int id = -1;
        for (int k = 0; k < n; k++)
            if(mark[k] == false && (id == -1 || timed[k] < timed[id])) id = k;
        mark[id] = true;
        if(timed[id] == numeric_limits<int>::max()) break;
        int tt = (id == begin) ? timed[id] : (timed[id] + 2), mm = tt % 60;
        for (int k = 0; k < stop[id].size(); k++) {
            int i = stop[id][k].first, j = stop[id][k].second;
            int mint = numeric_limits<int>::max(), cur = route[i].second[j].second;
            for (int l = 0; l < route[i].first.size(); l++) {
                int tmp = (cur + route[i].first[l]) % 60; // % 60 WA
                if(tmp >= mm) tmp = tmp - mm;
                else tmp = 60 + tmp - mm; // -(mm - tmp) WA
                if(tmp < mint) mint = tmp;
            }
            int t = tt + mint - cur;
            for (int l = j + 1; l < route[i].second.size(); l++) {
                int temp = route[i].second[l].first, tmp = t + route[i].second[l].second;
                if(mark[temp] == false && tmp < timed[temp])
                    timed[temp] = tmp;
            }
        }
    }
    delete[] mark;
}

int main(void)
{
    int l, buff;
    char buf[33];

    while(scanf("%d", &l) != EOF && l >= 0) {
        mp.clear();
        stop.clear();
        route.clear();
        for (int i = 0; i < l; i++) {
            route.push_back(Route::value_type());
            int sum = 0;
            for (int j = 0; scanf("%s%d", buf, &buff); j++) {
                string str(buf);
                map<string, int>::iterator itr = mp.find(str);
                int id;

                if(itr == mp.end()) {
                    id = mp.size();
                    mp.insert(make_pair(str, id));
                    stop.push_back(Stop::value_type());
                } else {
                    id = itr -> second;
                }
                stop[id].push_back(make_pair(i, j));
                route[i].second.push_back(make_pair(id, sum));
                if(buff < 0) break;
                sum += buff;
            }
            scanf("%d", &sum);
            while(sum--) {
                scanf("%d", &buff);
                route[i].first.push_back(buff);
            }
        }

        int begin[2], start[2];

        scanf("%d:%d%s", &start[0], &buff, buf);
        start[0] = start[0] * 60 + buff;
        if(mp.find((string)buf) == mp.end()) {
            scanf("%*d:%*d%*s");
            puts("No connection");
            continue;
        }
        else begin[0] = mp[(string)buf];
        scanf("%d:%d%s", &start[1], &buff, buf);
        start[1] = start[1] * 60 + buff;
        if(mp.find((string)buf) == mp.end()) {
            puts("No connection");
            continue;
        }
        else begin[1] = mp[(string)buf];

        bfs(begin[0], start[0], timed[0], stop, route);
        bfs(begin[1], start[1], timed[1], stop, route);
        for (int i = 0; i < stop.size(); i++)
            timed[0][i] = max(timed[0][i], timed[1][i]);
        timed[0][0] = *min_element(timed[0], timed[0] + stop.size());
        if(timed[0][0] == numeric_limits<int>::max()) puts("No connection");
        else printf("%d:%02d\n", timed[0][0] / 60 % 24, timed[0][0] % 60); // %02d PE
    }
    return 0;
}

// 2750398 2008-02-13 20:50:31 Accepted 2903 C++ 00:00.26 1112K ¤ï¤¿¤·

// 2012-09-07 01:46:09 | Accepted | 2903 | C++ | 100 | 320 | watashi | Source
