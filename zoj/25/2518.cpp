// my_na_p2

#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

template<class Tp, class Fo>
Tp RombergIntegral(Tp lowerBound, Tp upperBound, Fo f, Tp eps, int MAXK = 16){
    Tp h = upperBound - lowerBound;
    Tp *T = new double[MAXK];
    int K = 1;

    T[0] = (f(lowerBound) + f(upperBound)) * h / 2.0;

    double cmp = T[0];

    while(true){
        Tp tmp = 0;
        for(Tp x = lowerBound + h/2.0; x < upperBound; x += h)
            tmp += f(x);
        tmp = (T[0] + tmp * h) / 2.0;
        Tp power4 = 1.0;
        for(int i = 0; i < K; i++){
            power4 *= 4.0;
            Tp cur = tmp + (tmp - T[i]) / (power4 - 1.0);
            T[i] = tmp;
            tmp =cur;
        }
        T[K] = tmp;
        if(K>=4 && fabs(tmp - cmp) < eps) break;
        cmp = T[K];
        h /= 2.0;
        K++;
    }
    return T[K];
}

template<class T>
class EllipseFunction{
    private:
        T _a;
        T _c;
    public:
        EllipseFunction(T a = 0.0, T c = 0.0) : _a(a), _c(c) { }
        inline T operator()(T x){
            T cur = sin(x) * _c / _a;
            return sqrt(1 - cur * cur);
        }
};

int main()
{
    const double PI = acos(-1.0);
    const double lowerBound = 0.0, upperBound = PI / 2.0;
    double h, a, b;

    while(cin >> h >> a >> b) {
        if(a < b)
            swap(a, b);
        EllipseFunction<double> fuction(a, sqrt(a * a - b * b));
        double perimeter = 4.0 * a * RombergIntegral<double,EllipseFunction<double> >(lowerBound, upperBound, fuction, 1e-10);
        cout << setiosflags(ios::fixed) << setprecision(2) << h * perimeter << endl;
    }
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2874915   2008-04-27 19:18:08     Accepted    2518    C++     00:00.00    848K    Re:ReJudge

// 2012-09-07 01:26:27 | Accepted | 2518 | C++ | 0 | 188 | watashi | Source
