// 好题～～

// 考虑相邻两个if(fa * lb < fb * la) swapi -> 冒泡
// 可证明比较f/l可
// zan

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Song
{
    public:
        Song(int id = 0, double value = 0.0) : id(id), value(value) { }
        bool operator<(const Song& rhs) const { return value > rhs.value; }
        int name() const { return id; }
    private:
        int id;
        double value;
};

int main(void)
{
    int n, k;
    double l, f;

    while(scanf("%d", &n) != EOF) {
        vector<Song> songs(n);
        for(int i = 0; i < n; i++) {
            scanf("%d%lf%lf", &k, &l, &f);
            songs[i] = Song(k, f / l);
        }
        sort(songs.begin(), songs.end());
        scanf("%d", &k);
        printf("%d\n", songs[k - 1].name());
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2844337   2008-04-14 21:53:37     Accepted    2579    C++     00:00.07    904K    Re:ReJudge

// 2012-09-07 01:29:50 | Accepted | 2579 | C++ | 20 | 180 | watashi | Source
