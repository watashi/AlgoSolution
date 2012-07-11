#include <set>
#include <cstdio>
#include <functional>

using namespace std;

template<typename S, typename T>
void pop(S& s, T& t) {
    t.insert(*s.begin());
    s.erase(s.begin());
}

int main() {
    int n, m, x;
    multiset<int> a;
    multiset<int, greater<int> > b;

    scanf("%d", &n);
    m = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d", &x);
            if (b.empty() || x <= *b.begin()) {
                b.insert(x);
            } else {
                a.insert(x);
            }
            ++m;
            while ((int)a.size() < m / 3) {
                pop(b, a);
            }
            while ((int)a.size() > m / 3) {
                pop(a, b);
            }
        } else {
            if (a.empty()) {
                puts("No reviews yet");
            } else {
                printf("%d\n", *a.begin());
            }
        }
    }

    return 0;
}

//Correct Answer
//Execution Time: 4.66
