// 当时yy未证明，类似Huffman
// 标程也是二分的

#include <queue>
#include <cstdio>
using namespace std;

const double eps = 1e-8;

double total(priority_queue <double, vector<double>, greater<double> > pq, double r, double value = -1.0)
{
    if(value > 0) pq.push(value);
    while(pq.size() > 1) {
        value = 0.0;
        value += pq.top();
        pq.pop();
        value += pq.top();
        pq.pop();
        pq.push(r * value);
    }
    return pq.top();
}

int main(void)
{
    int t;

    scanf("%d", &t);
    while(t--) {
        int w, p, n, a;
        double rr;
        priority_queue <double, vector<double>, greater<double> > pq;

        scanf("%d%d%d", &w, &p, &n);
        rr = 100.0 / (100 - p);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            pq.push(a);
        }
        if(total(pq, rr) > w + eps) printf("-1\n");
        else {
            double l = 0.0, r = w;
            while(r - l > eps) {
                double m = (l + r) / 2.0;
                if(total(pq, rr, m) > w) r = m;
                else l = m;
            }
            printf("%lf\n", l);
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2758096 2008-02-23 12:16:08 Accepted 2917 C++ 00:00.01 848K わたし

// 2012-09-07 01:47:10 | Accepted | 2917 | C++ | 0 | 180 | watashi | Source
