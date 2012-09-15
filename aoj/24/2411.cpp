#include <map>
#include <cstdio>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int MAXM = 3652425;

int t[MAXN], x[MAXN], y[MAXN];
long long w[MAXN];
long long s[MAXM + 100];
multimap<long long, int> mp;
multimap<int, pair<bool, int> > todo;

int main() {
    int n, q;
    long long c[3], ans;

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> t[i] >> x[i];
        mp.insert(make_pair(w[i], i));
    }

    ans = 0;
    fill(c, c + 3, 0);
    c[0] = 1;
    fill(y, y + n, MAXM + 100);
    for (int i = 0; i < MAXM + 100; ++i) {
        s[i] = ans;
        while (!mp.empty() && mp.begin()->first <= ans) {
            int k = mp.begin()->second;
            mp.erase(mp.begin());
            y[k] = i;
            todo.insert(make_pair(i, make_pair(true, k)));
            todo.insert(make_pair(i + x[k], make_pair(false, k)));
        }
        while (!todo.empty() && todo.begin()->first == i) {
            bool flag = todo.begin()->second.first;
            int k = todo.begin()->second.second;
            todo.erase(todo.begin());
            if (flag) {
                switch (t[k]) {
                case 0:
                    c[0] += 1;
                    break;
                case 1:
                    c[1] += 1;
                    break;
                case 2:
                    c[2] += 2;
                    c[1] += -1;
                    break;
                }
            } else {
                switch (t[k]) {
                case 0:
                    c[0] -= 1;
                    break;
                case 1:
                    c[1] -= 1;
                    c[0] -= x[k];
                    break;
                case 2:
                    c[2] -= 2;
                    c[1] -= 2 * x[k] - 1;
                    c[0] -= x[k] * x[k];
                    break;
                }
            }
        }
        c[1] += c[2];
        c[0] += c[1];
        ans += c[0];
    }

    for (int i = 0; i < n; ++i) {
        if (y[i] <= MAXM) {
            cout << y[i] << "\n";
        } else {
            cout << "Many years later\n";
        }
    }

    for (int i = 0; i < q; ++i) {
        cin >> n;
        cout << s[n] << "\n";
    }

    return 0;
}

//Run# 	提出者 	問題 	結果 	言語 	時間 	メモリ 	コード長 	提出日時
//#485473 	watashi 	2411 	: Accepted 	C++ 	00:30 sec 	44192 KB 	2294 Bytes 	Sat Sep 15 17:14:15

