#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class ARRAY
{
        friend istream& operator>>(istream& is, ARRAY& a);
    public:
        string name() const;
        bool operator<(const ARRAY& rhs) const;
        string operator[](const vector<int>& i) const;
    private:
        string id;
        int c0;
        vector<int> c;
};

string ARRAY::name() const
{
    return id;
}

bool ARRAY::operator<(const ARRAY& rhs) const
{
    return id < rhs.id;
}

string ARRAY::operator[](const vector<int>& i) const
{
    int ret = c0;
    ostringstream oss;

    oss << id << "[";
    for (size_t j = 0; j < c.size(); j++) {
        ret += c[j] * i[j];
        if(j > 0)
            oss << ", ";
        oss << i[j];
    }
    oss << "] = " << ret;

    return oss.str();
}

istream& operator>>(istream& is, ARRAY& a)
{
    int B, D, CD;
    vector<int> L, U;

    is >> a.id >> B >> CD >> D;
    L.resize(D);
    U.resize(D);
    for (int i = 0; i < D; i++)
        is >> L[i] >> U[i];
    a.c.resize(D);
    a.c[D - 1] = CD;
    for (int i = D - 1; i > 0; i--)
        a.c[i - 1] = a.c[i] * (U[i] - L[i] + 1);
    a.c0 = B;
    for (int i = 0; i < D; i++)
        a.c0 -= a.c[i] * L[i];

    return is;
}

int main(void)
{
    int n, m;
    string id, str;
    istringstream iss;
    vector<int> arg;
    ARRAY array;
    map<string, ARRAY> mp;

    cin >> n >> m;
    while(n--) {
        cin >> array;
        mp[array.name()] = array;
//      cout << array.name() << endl;
    }
//  cout << "@@" << endl;
    getline(cin, str);
    while(m--) {
        getline(cin, str);
        iss.clear();
        iss.str(str);
        iss >> id;
        arg.clear();
        while(iss >> n)
            arg.push_back(n);
//      cout << id << arg[0] << endl;
        cout << mp[id][arg] << endl;
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2842063   2008-04-13 19:06:15     Accepted    1722    C++     00:00.01    876K    Re:ReJudge

// 2012-09-07 00:58:54 | Accepted | 1722 | C++ | 0 | 188 | watashi | Source
