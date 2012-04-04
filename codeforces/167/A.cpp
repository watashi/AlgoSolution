#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    double a, d, t, v, w, ww, dd, tt, ans;

    cin >> n >> a >> d;
    ww = 2 * a * d;
    w = sqrt(ww);
    ans = -1;
    for (int i = 0; i < n; ++i) {
        cin >> t >> v;
        if (v > w) {
            tt = w / a;
        } else {
            tt = v / a;
            dd = d - v * tt / 2;
            tt += dd / v;
        }
        t += tt;
        ans = max(ans, t);
        cout << fixed << setprecision(10) << ans << "\n";
    }

    return 0;
}

