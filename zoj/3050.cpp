#include <set>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

// righttop (0, 0)
//  0
// +--+
//5|6 |1
// +--+
//4|3 |2
// +--+

typedef pair<int, int> Point;
typedef pair<Point, Point> Line;

const int mask[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

Line line1(int x, int y, int dx, int dy)
{
    return make_pair(make_pair(x, y), make_pair(x + dx, y + dy));
}

Line line2(int x, int y, int dx, int dy)
{
    return make_pair(make_pair(x + dx, y + dy), make_pair(x, y));
}

int judge(const set<Line>& st, const int l)
{
    int m = 0;
/*
    for (set<Line>::iterator i = st.begin(); i != st.end(); ++i) {
        printf("%d %d %d %d\n", i->first.first, i->first.second, i->second.first, i->second.second);
    }
*/
    if (st.count(line1(0, 0, 0, 1)) || st.count(line2(0, 0, 0, 1))) m |= 1;
    if (st.count(line1(0, 0, 1, 0)) || st.count(line2(0, 0, 1, 0))) m |= 2;
    if (st.count(line1(l, 0, 1, 0)) || st.count(line2(l, 0, 1, 0))) m |= 4;
    if (st.count(line1(2 * l, 0, 0, 1)) || st.count(line2(2 * l, 0, 0, 1))) m |= 8;
    if (st.count(line1(l, l, 1, 0)) || st.count(line2(l, l, 1, 0))) m |= 16;
    if (st.count(line1(0, l, 1, 0)) || st.count(line2(0, l, 1, 0))) m |= 32;
    if (st.count(line1(l, 0, 0, 1)) || st.count(line2(l, 0, 0, 1))) m |= 64;

//  printf("m = %d\n", m);
    for (int i = 0; i < 10; i++) {
        if (mask[i] == m) {
            return i;
        }
    }

    return -1;
}

char buf[128];

int main(void)
{
    while (scanf("%s", buf) != EOF) {
        bool flag;
        Point p, pp;
        vector<Point> vp;
        vector<Line> vl;

        flag = true;
        p = make_pair(0, 0);
        for (int i = 0; buf[i]; i++) {
            if (buf[i] == 'u' || buf[i] == 'd') {
                flag = (buf[i] == 'd');
                continue;
            }
            pp = p;
            switch(buf[i]) {
                case 'U': --pp.first; break;
                case 'D': ++pp.first; break;
                case 'L': ++pp.second; break;
                case 'R': --pp.second; break;
            }
            if (flag) {
                vl.push_back(make_pair(p, pp));
                vp.push_back(p);
                vp.push_back(pp);
            }
            p = pp;
        }

        int x = vp[0].first, y = vp[0].second, l = 0;

        for (size_t i = 0; i < vp.size(); i++) {
            x = min(x, vp[i].first);
            y = min(y, vp[i].second);
        }
        for (size_t i = 0; i < vp.size(); i++) {
            l = max(l, vp[i].first - x);
        }
        //
        l /= 2;
        //printf("l = %d\n", l);

        set<Line> sl;
        for (size_t i = 0; i < vl.size(); i++) {
            vl[i].first.first -= x;
            vl[i].first.second -= y;
            vl[i].second.first -= x;
            vl[i].second.second -= y;
            sl.insert(vl[i]);
        }
        printf("%d\n", judge(sl, l));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1711136   2008-11-26 21:24:41     Accepted    3050    C++     0   176     watashi@Zodiac












/*
//by Murphy

#include    <cstdio>
#include    <cstdlib>
#include    <cstring>
#include    <string>
#include    <vector>
#include    <cmath>
#include    <algorithm>
#include    <cassert>
#include    <set>
#include    <map>
#include    <queue>
#include    <iostream>
#include <fstream>
using namespace std;
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);i++ )

typedef long long LL;
typedef pair<int,int> piii;

map<int,piii> z;
set<int> h;

int main()
{
        string s;
        while (cin>>s)
        {
                int v=1,x=0,y=0;
                h.clear();z.clear();
                REP(i,s.size())
                {
                        char t=s[i];
                        if (t=='u')
                                v=0;
                        else
                                if (t=='d')
                                        v=1;
                        //if (v)
                        {
                                if (t=='U')
                                {
                                        y--;
                                        if (v)
                                        {
                                                if (z.find(x)==z.end())
                                                {
                                                        piii p=make_pair(y,y+1);
                                                        z[x]=p;
                                                }
                                                else
                                                {
                                                        piii p=z[x];
                                                        p.first=min(p.first,y);
                                                        p.second=max(p.second,y+1);
                                                        z[x]=p;
                                                }
                                        }
                                }
                                if (t=='D')
                                {
                                        y++;
                                        //y--;
                                        if (v)
                                        {
                                                if (z.find(x)==z.end())
                                                {
                                                        piii p=make_pair(y-1,y);
                                                        z[x]=p;
                                                }
                                                else
                                                {
                                                        piii p=z[x];
                                                        p.first=min(p.first,y-1);
                                                        p.second=max(p.second,y);
                                                        z[x]=p;
                                                }
                                        }
                                }
                                if (t=='L')
                                {
                                        x--;
                                        if (v)
                                        h.insert(y);
                                }
                                if (t=='R')
                                {
                                        x++;
                                        if (v)
                                        h.insert(y);
                                }
                        }
                }
                int hs=h.size(),zs=z.size();
                int res;
                if (hs==2  && zs==2)
                        res=0;
                if (hs==0  && zs==1)
                        res=1;
                if (hs==3  && zs==1)
                        res=3;
                if (hs==1  && zs==2)
                        res=4;
                if (hs==1  && zs==1)
                        res=7;
                if (hs==3  && zs==2)
                {
                        int tot=0;
                        int x[2][3];
                        memset(x,-1,sizeof x);
                        for (map<int,piii>::iterator i=z.begin();i!=z.end();i++)
                        {
                                x[tot][0]=i->first;
                                x[tot][1]=i->second.first;
                                x[tot][2]=i->second.second;
                                tot++;
                        }
//                        /*REP(i,2)
//                        {
//                                REP(j,3)
//                                        cout<<x[i][j]<<' ';
//                        cout<<endl;
//                        }* /
                        if (x[0][0]>x[1][0])
                        {
                                swap(x[0][1],x[1][1]);
                                swap(x[0][2],x[1][2]);
                        }
                        if (x[0][1]==x[1][1])
                                res=x[0][2]==x[1][2]?8:9;
                        else
                                if (x[0][2]==x[1][2])
                                        res=6;
                                else
                                        if (x[0][1]==x[1][2])
                                                res=2;
                                        else
                                                res=5;
                }
                cout<<res<<endl;
        }
        return 0;
}

*/

// 2012-09-07 01:58:40 | Accepted | 3050 | C++ | 0 | 180 | watashi | Source
