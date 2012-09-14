#include <set>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

class Call
{
    public:
        int t, e;
        friend istream& operator>>(istream& is, Call& c)
        {
            is >> c.t;
            if(c.t == 9000) {
                is.setstate(ios_base::failbit);
            }
            else {
                is >> c.e;
            }

            return is;
        }
};

class Request
{
    private:
        int s, t, x, y;
    public:
        int src() const
        {
            return s;
        }
        int tar() const
        {
            return t;
        }
        int begin() const
        {
            return x;
        }
        int end() const
        {
            return x + y;
        }
        friend bool operator<(const Request& lhs, const Request& rhs)
        {
            return lhs.end() < rhs.end();
        }
        friend istream& operator>>(istream& is, Request& r)
        {
            is >> r.s;
            if(r.s == 0) {
                is.setstate(ios_base::failbit);
            }
            else {
                is >> r.x >> r.y >> r.t;
            }

            return is;
        }
};

class pr
{
    public:
        bool operator()(const Request& lhs, const Request& rhs)
        {
            return lhs.begin() < rhs.begin();
        }
};

class System
{
    private:
        vector<int> f;
        Request r;
        Call c;
    public:
        System() : f(10000)
        {
        }
        void run()
        {
            vector<Request> v;
            while(cin >> r) {
                v.push_back(r);
            }
            sort(v.begin(), v.end(), pr());
            cin.clear();

            set<Request> st;
            vector<Request>::size_type i = 0;
            while(cin >> c) {
                while(!st.empty() && st.begin()->end() < c.t) {
                    f[st.begin()->src()] = 0;
                    st.erase(st.begin());
                }
                while(i < v.size() && v[i].begin() <= c.t) {
                    f[v[i].src()] = v[i].tar();
                    st.insert(v[i]);
                    ++i;
                }

                set<int> mk;
                int p = c.e;
                while(f[p] != 0) {
                    if(mk.count(p) != 0)
                        break;
                    mk.insert(p);
                    p = f[p];
                }

                cout.fill('0');
                cout << "AT " << setw(4) << c.t << " CALL TO " << setw(4) << c.e << " RINGS "
                    << setw(4) << (f[p] == 0 ? p : 9999) << endl;
            }
            cin.clear();
        }
};

int main(void)
{
    int re;
    System *psys;

    cin >> re;
    cout << "CALL FORWARDING OUTPUT" << endl;
    for (int ri = 1; ri <= re; ri++) {
        cout << "SYSTEM " << ri << endl;
        psys = new System();
        psys->run();
        delete psys;
    }
    cout << "END OF OUTPUT" << endl;
}
//2874239   2008-04-27 15:22:45     Accepted    1282    C++     00:00.01    884K    Re:ReJudge

// 2012-09-07 00:44:22 | Accepted | 1282 | C++ | 0 | 188 | watashi | Source
