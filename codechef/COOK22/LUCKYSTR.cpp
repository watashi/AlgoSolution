#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    string s;
    vector<string> v;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (s.length() >= 47) {
            s = "";
        }
        for (int j = 0; j < n && !s.empty(); ++j) {
            if (s.find(v[j]) != string::npos) {
                s = "";
            }
        }
        cout << (s.empty() ? "Good" : "Bad") << endl;
    }

    return 0;
}

