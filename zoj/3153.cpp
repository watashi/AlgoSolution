#include <set>
#include <map>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

// l, r -> [l, r)

class LotteryPool
{
    private:
        static const int MAXN = 1 << 14;
        static const int MAXSIZE = 1 << 15;
        static const int inf = 1234567890;

        int pool;
        set<int> ids;

        typedef map<int, set<int> > Node;
        vector<Node> va;

        class Record
        {
            public:
                string name;
                int al, ar, b;
                Record(const string& name, int al, int ar, int b)
                    : name(name), al(al), ar(ar), b(b)
                {

                }
        };
        vector<Record> vp;

        void insert(int id, int b, int al, int ar, int l, int r, int i)
        {
            if (al == l && ar == r) {
                va[i][b].insert(id);
                return;
            }
            int m = (l + r) / 2;
            if (ar <= m) {
                insert(id, b, al, ar, l, m, 2 * i + 1);
            }
            else if (al >= m) {
                insert(id, b, al, ar, m, r, 2 * i + 2);
            }
            else {
                insert(id, b, al, m, l, m, 2 * i + 1);
                insert(id, b, m, ar, m, r, 2 * i + 2);
            }
        }

        void erase(int id, int b, int al, int ar, int l, int r, int i)
        {
            if (al == l && ar == r) {
                va[i][b].erase(id);
                if (va[i][b].size() == 0) {
                    va[i].erase(b);
                    // this is important!!, or find_d will get wrong answer
                }
                return;
            }
            int m = (l + r) / 2;
            if (ar <= m) {
                erase(id, b, al, ar, l, m, 2 * i + 1);
            }
            else if (al >= m) {
                erase(id, b, al, ar, m, r, 2 * i + 2);
            }
            else {
                erase(id, b, al, m, l, m, 2 * i + 1);
                erase(id, b, m, ar, m, r, 2 * i + 2);
            }
        }

        void find_id(int b, int a, int l, int r, int i)
        {
            if (l != r - 1) {
                int m = (l + r) / 2;
                if (a < m) {
                    find_id(b, a, l, m, 2 * i + 1);
                }
                else {
                    find_id(b, a, m, r, 2 * i + 2);
                }
            }

            Node::const_iterator itr = va[i].find(b);
            if (itr != va[i].end()) {
                ids.insert(itr->second.begin(), itr->second.end());
            }
        }

        int find_d(int b, int a, int l, int r, int i)
        {
            int ret = inf;

            if (l != r - 1) {
                int m = (l + r) / 2;
                if (a < m) {
                    ret = find_d(b, a, l, m, 2 * i + 1);
                }
                else {
                    ret = find_d(b, a, m, r, 2 * i + 2);
                }
            }

            Node::const_iterator itr = va[i].lower_bound(b);
            if (itr != va[i].end()) {
                if (itr->first - b < ret) {
                    ret = itr->first - b;
                }
            }
            if (itr != va[i].begin()) {
                --itr;
                if (b - itr->first < ret) {
                    ret = b - itr->first;
                }
            }

            return ret;
        }

    public:
        LotteryPool() : va(MAXSIZE)
        {

        }

        void init(int pool)
        {
            for (int i = 0; i < MAXSIZE; i++) {
                va[i].clear();
            }
            vp.clear();
            this->pool = pool;
        }

        void add(const string& name, int al, int ar, int b)
        {
            pool += ar - al;
            vp.push_back(Record(name, al, ar, b));
            insert(vp.size() - 1, b, al, ar, 0, MAXN, 0);
        }

        void draw(int a, int b)
        {
            int d = find_d(b, a, 0, MAXN, 0);

            ids.clear();
            find_id(b + d, a, 0, MAXN, 0);
            find_id(b - d, a, 0, MAXN, 0);
            if (ids.size() == 0) {
                printf("0\n");
                return;
            }

            int prize = pool / ids.size();
            map<string, int> ans;

            pool -= prize * ids.size();
            for (set<int>::const_iterator i = ids.begin(); i != ids.end(); ++i) {
                ans[vp[*i].name] += prize;
                erase(*i, vp[*i].b, vp[*i].al, vp[*i].ar, 0, MAXN, 0);
            }
            printf("%u\n", ans.size());
            for (map<string, int>::const_iterator i = ans.begin(); i != ans.end(); ++i) {
                printf("%s %d\n", i->first.c_str(), i->second);
            }
        }
};

int main(void)
{
    int n, m;
    int op, al, ar, a, b;
    static char buf[1024];
    LotteryPool lp;

    while (scanf("%d%d", &n, &m) != EOF) {
        lp.init(m);
        while (n--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%s%d%d%d", buf, &al, &ar, &b);
                lp.add(buf, al, ar + 1, b);
            }
            else {
                scanf("%d%d", &a, &b);
                lp.draw(a, b);
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1748016   2009-01-24 17:20:08     Accepted    3153    C++     3720    41976   watashi@Zodiac

// 2012-09-07 02:04:04 | Accepted | 3153 | C++ | 3580 | 41980 | watashi | Source
