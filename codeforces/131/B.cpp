#include <map>
#include <iostream>

using namespace std;

int main() {
    int n, a;
    long long ans;
    map<int, int> mp;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ++mp[a];
    }
    ans = 1LL * mp[0] * (mp[0] - 1) / 2;
    for (map<int, int>::const_iterator it = mp.upper_bound(0); it != mp.end(); ++it) {
        map<int, int>::const_iterator jt = mp.find(-it->first);
        if (jt != mp.end()) {
            ans += 1LL * it->second * jt->second;
        }
    }
    cout << ans << endl;

    return 0;
}

