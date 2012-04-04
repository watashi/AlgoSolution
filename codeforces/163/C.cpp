#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long m, d, v1, v2;
    vector<long long> v, w, p;

    cin >> n;
    cin >> m >> v1 >> v2;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i] *= v1 + v2;
    }
    d = m * v2;
    m = 2 * m * (v1 + v2);

    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        v.push_back(v[i] + m);
    }
    p.push_back(0);
    p.push_back(m);
    for (long long i: v) {
        // cout << i << " ";
        if (i < m) {
            p.push_back(i);
        }
        if (0 <= i - d && i - d < m) {
            p.push_back(i - d);
        }
    }
    // cout << endl;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    w.resize(n + 1);
    for (int i = 1; i < (int)p.size(); ++i) {
        int l = upper_bound(v.begin(), v.end(), p[i - 1]) - v.begin();
        int r = upper_bound(v.begin(), v.end(), p[i - 1] + d) - v.begin();
        // cout << p[i - 1] << " " << p[i] << ": " << r << " - " << l << endl;
        w[r - l] += p[i] - p[i - 1];
    }
    for (long long i: w) {
        printf("%.16lf\n", 1.0 * i / m);
    }

    return 0;
}

