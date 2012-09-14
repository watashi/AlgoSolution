#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <vector>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <string>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <sstream>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <iostream>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <complex>

using namespace std;

typedef complex<long double> Complex;
typedef vector<Complex> Vector;

Vector toV(const string& str)
{
    istringstream iss(str);
    Vector ret;
    Complex c;

    while (iss >> c) {
        ret.push_back(c);
    }

    return ret;
}

int main(void)
{
    string buf;
    long double p;
    long double ans;

    while (getline(cin, buf)) {
        Vector a, b;

        a = toV(buf);
        getline(cin, buf);
        b = toV(buf);
        cin >> p;
        while (cin.get() != '\n');
        if (a.size() != b.size()) {
            throw 1;
        }
        ans = 0.0;
        for (size_t i = 0; i < a.size(); i++) {
            ans += powl(abs(a[i] - b[i]), p);
        }
        printf("%.16Le\n", powl(ans, 1.0 / p));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//733   2011-04-24 02:01:21     Accepted    E   C++     0   188     watashi@ArcOfDream  Source

// 2012-09-07 16:51:12 | Accepted | 3504 | C++ | 0 | 188 | watashi | Source
