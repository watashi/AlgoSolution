#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class Rec
{
private:
    int o, d, t;
    list<int> p;
public:
    Rec(int o, int d, int t, int pre[]): o(o), d(d), t(t)
    {
        p.clear();
        p.push_front(d);
        while(p.front() != o)
            p.push_front(pre[p.front()]);
    }
    bool operator<(const Rec& rhs) const
    {
        return t < rhs.t;
    }
    friend ostream& operator<<(ostream& os, const Rec& rhs)
    {
        os << rhs.o + 1 << "\t" << rhs.d + 1 << "\t" << rhs.t;
        for (list<int>::const_iterator it = rhs.p.begin(); it != rhs.p.end(); ++it)
            os << "\t" << *it + 1;
        return os;
    }
};

vector<Rec> vr;
int mp[22][22];
int mind[22];
int pre[22];
bool mark[22];

void Dijkstra(int n, int s, int t)
{
    fill(mark, mark + n, false);
    fill(mind, mind + n, -1);
    fill(pre, pre + n, -1);
    mind[s] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if(!mark[j] && mind[j] != -1 && (k == -1 || mind[j] < mind[k]))
                k = j;
        // if(k == -1)
        if(k == t) {
            vr.push_back(Rec(s, t, mind[k], pre));
            return;
        }
        mark[k] = true;
        for (int j = 0; j < n; j++)
            if(!mark[j] && mp[k][j] != -1 && (mind[j] == -1 || mind[k] + mp[k][j] < mind[j])) {
                mind[j] = mind[k] + mp[k][j];
                pre[j] = k;
            }
    }
}

int main(void)
{
    bool blank = false;
    int re, n, s, t;
    string buf;

    cin >> re;
    while(re--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mp[i][j];
        while(cin.get() != '\n');
        getline(cin, buf);
        vr.clear();
        istringstream is(buf);
        is >> t;
        while(is >> s)
            Dijkstra(n, s - 1, t - 1);
        sort(vr.begin(), vr.end());
        if(blank) cout << endl;
        else blank = true;
        cout << "Org\tDest\tTime\tPath" << endl;
        for (size_t i = 0; i < vr.size(); i++)
            cout << vr[i] << endl;
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2799335 2008-03-23 20:13:05 Accepted 1053 C++ 00:00.00 872K ¤ï¤¿¤·

// 2012-09-07 00:34:38 | Accepted | 1053 | C++ | 0 | 188 | watashi | Source
