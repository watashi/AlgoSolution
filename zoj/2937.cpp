// solution for Guard by whatashya@ZJU

/* Guard

// Andy Harrington, Loyola University Chicago

Basic idea:  The number of possible places that guards might be
places can be limited to p(p+1)/2, and then all combinations of
g guards can be tested recursively.  With the problem limiting
c to 11 and g to 4, the number of combinations <= 66C4 = 720720.

Details of determining the places:  All the intersections and
places where there are valuables are possibilities.  These are a
subset of the p labeled points.  If a guard is not placed at one
of these points and minimizes the risk for one item that has the
maximum risk for the whole site, then the guard could be moved
closer unless there is another item being guarded by this person
with the same risk.  (It cannot be higher, since the assumption
was the first item caused the maximum risk.  It could not be
less or it would not inhibit the guard from moving closer to the
first item.)  The risk formula is a moment with the value as
weight, so the point between two items balancing the risk is the
centroid (center of mass).  Thus the further points to be considered
are the centroids of pairs of distinct points with items that are
along the same corridor.  There would be the most places to check if
all p items were on one corridor, with p(p-1)/2 centroid locations.
Adding the original p locations the most to consider is p(p+1)/2.

In the solution the array of points pt, does double duty:  The
first p location are the possible locations of valuables, and
are referenced when distances to valuables are considered.  Then
the rest of the locations used in the array are taken by the
centroids, so all positions used in the array contains possible
locations for guards.  One listed location might balance maximal risks
for more than one pair of items, but that will just make the point
appear more than once in the list, which does not hurt.

*/

#include <map>
#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    double x;
    double y;
    int mask;
};

int p, c, g, n;
int v[12], mask[12], all;
Point pt[100];
double risk[100][12];
double ans;

inline double dist(const Point& lhs, const Point& rhs)
{
    double x = lhs.x - rhs.x, y = lhs.y - rhs.y;
    return sqrt(x * x + y * y);
}

void dfs(const vector<double>& arg, int level, int bound)
{
    if(level == 0) {
        ans = min(ans, *max_element(arg.begin(), arg.end()));
        return;
    }
    vector<double> cmp(p);
    --level;
    for (int i = bound + 1; i < n; i++) {
        for (int j = 0; j < p; j++)
            cmp[j] = min(arg[j], risk[i][j]);
        dfs(cmp, level, i);
    }
}

int main(void)
{
    char ch, str[12];

    while(scanf("%d", &p) != EOF && p != 0) {
        scanf("%d%d", &c, &g);
        all = 0;
        map<char, int> mp;
        for (n = 0; n < p; n++) {
            scanf(" %c%lf%lf%d", &ch, &pt[n].x, &pt[n].y, &v[n]);
            pt[n].mask = 0;
            all |= 1 << n;
            mp.insert(make_pair(ch, n));
        }
        for (int i = 0; i < c; i++) {
            mask[i] = 0;
            scanf("%s", str);
            int m = 0, tmp[12];
            while(str[m] != '\0') {
                tmp[m] = mp[str[m]];
                mask[i] |= 1 << tmp[m];
                ++m;
            }
            for (int j = 0; j < m; j++) {
                pt[tmp[j]].mask |= mask[i];
                for (int k = 0; k < j; k++) {
                    pt[n].x = (pt[tmp[j]].x * v[tmp[j]] + pt[tmp[k]].x * v[tmp[k]]) / (v[tmp[j]] + v[tmp[k]]);
                    pt[n].y = (pt[tmp[j]].y * v[tmp[j]] + pt[tmp[k]].y * v[tmp[k]]) / (v[tmp[j]] + v[tmp[k]]);
                    pt[n].mask = mask[i];
                    ++n;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                if((pt[i].mask & (1 << j)) == 0) risk[i][j] = numeric_limits<double>::max();
                else risk[i][j] = dist(pt[i], pt[j]) * v[j];
            }
        }
        ans = numeric_limits<double>::max();
        vector<double> cmp(p, numeric_limits<double>::max());
        dfs(cmp, g, -1);
        if(ans == numeric_limits<double>::max()) printf("too few guards\n");
        else printf("%.2lf\n", ans);
    }
    return 0;
}

// Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
// 569 2008-02-03 21:00:29 Accepted 1044 C++ 00:00:25 860K わたし

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2768719 2008-03-03 16:43:32 Accepted 2937 C++ 00:00.25 860K わたし

// 2012-09-07 01:48:48 | Accepted | 2937 | C++ | 110 | 192 | watashi | Source
