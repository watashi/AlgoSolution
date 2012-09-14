#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

class Team{
private:
    string Nm;
    int w, d, l;
    int Pt;
    int Gd;
public:
    Team(string name) : Nm(name)
    {
        w = d = l = 0;
        Pt = Gd = 0;
    }
    inline void doit(int a, int b)
    {
        if(a > b) {
            w++;
            Pt += 3;
            Gd += a - b;
        } else if(a < b) {
            l++;
            Gd += a - b;
        } else {
            d++;
            Pt++;
        }
    }
    inline void print() const
    {
        printf("%s %d %d %d %d %d", Nm.c_str(), w, d, l, Pt, Gd);
    }
    inline bool operator<(const Team& that) const
    {
        if(Pt == that.Pt){
            if(Gd == that.Gd) {
                return Nm < that.Nm;
            } else return Gd > that.Gd;
        } else return Pt > that.Pt;
    }
};

int main()
{
    bool blank = false;
    int m;
    char str[22];

    while(scanf("%d", &m) != EOF) {
        if(blank) putchar('\n');
        else blank = true;
        vector<Team> ranklist;
        map<string, int> mp;
        while(m--) {
            int a, b;
            scanf("%s %d:%d ", str, &a, &b);
            int i;
            string istr(str);
            if(mp.find(istr) != mp.end()) i = mp[istr];
            else{
                i = ranklist.size();
                mp.insert(make_pair(istr, i));
                ranklist.push_back(Team(istr));
            }
            ranklist[i].doit(a, b);
            scanf("%s", str);
            int j;
            string jstr(str);
            if(mp.find(jstr) != mp.end()) j = mp[jstr];
            else{
                j = ranklist.size();
                mp.insert(make_pair(jstr, j));
                ranklist.push_back(Team(jstr));
            }
            ranklist[j].doit(b, a);
        }
        sort(ranklist.begin(), ranklist.end());
        for (int i = 0; i < ranklist.size(); i++) {
            printf("%d ", i + 1);
            ranklist[i].print();
            putchar('\n');
        }
    }
    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2722591   2008-01-10 13:45:21     Accepted    2524    C++     00:00.44    1544K   ¤ï¤¿¤·

// 2012-09-07 01:26:39 | Accepted | 2524 | C++ | 150 | 1316 | watashi | Source
