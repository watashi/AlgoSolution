#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a, b;
    long long sum, tmp;
    vector<vector<int> > ans;
    vector<pair<int, int> > s, p;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (b == 1) {
            s.push_back({a, i + 1});
        } else {
            p.push_back({a, i + 1});
        }
    }
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());

    sum = 0;
    ans.resize(m);
    for (int i = 0; i < m - 1 && !s.empty(); ++i) {
        sum += s.back().first;
        ans[i].push_back(s.back().second);
        s.pop_back();
    }
    if (!s.empty()) {
        tmp = s.front().first;
        while (!s.empty()) {
            tmp = min<long long>(tmp, s.back().first);
            sum += 2 * s.back().first;
            ans[m - 1].push_back(s.back().second);
            s.pop_back();
        }
        while (!p.empty()) {
            tmp = min<long long>(tmp, p.back().first);
            sum += 2 * p.back().first;
            ans[m - 1].push_back(p.back().second);
            p.pop_back();
        }
        sum -= tmp;
    } else {
        for (int i = 0; i < m; ++i) {
            if (ans[i].empty()) {
                sum += 2 * p.back().first;
                ans[i].push_back(p.back().second);
                p.pop_back();
            }
        }
        while (!p.empty()) {
            sum += 2 * p.back().first;
            ans[m - 1].push_back(p.back().second);
            p.pop_back();
        }
    }

    cout << sum / 2 << "." << sum % 2 * 5 << endl;
    for (int i = 0; i < m; ++i) {
        cout << ans[i].size();
        for (int j: ans[i]) {
            cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}

