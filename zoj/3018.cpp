#include <cctype>
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

// 坐标只能处理非负数
class QuadTree
{
    class __quad_tree_node
    {
        friend class QuadTree;
        int cnt, sum;
        int x1, x2, y1, y2;
        __quad_tree_node* p[4];
        __quad_tree_node(int xmin, int xmax, int ymin, int ymax)
        {
            cnt = 0;
            sum = 0;
            x1 = xmin;
            x2 = xmax;
            y1 = ymin;
            y2 = ymax;
            for (int i = 0; i < 4; i++) {
                p[i] = NULL;
            }
        }
        ~__quad_tree_node()
        {
            for (int i = 0; i < 4; i++) {
                delete p[i];
            }
        }
        __quad_tree_node* get_p(int d)
        {
            if (p[d] == NULL) {
                int x0 = (x1 + x2) / 2, y0 = (y1 + y2) / 2;
                switch (d) {
                    case 0: p[d] = new __quad_tree_node(x0, x2, y0, y2); break;
                    case 1: p[d] = new __quad_tree_node(x1, x0, y0, y2); break;
                    case 2: p[d] = new __quad_tree_node(x1, x0, y1, y0); break;
                    case 3: p[d] = new __quad_tree_node(x0, x2, y1, y0); break;
                }
            }

            return p[d];
        }
    };
public:
    typedef __quad_tree_node node_type;
    typedef __quad_tree_node* node_pointer;
protected:
    node_pointer root;
private:
    int x, y, s;
    int x1, x2, y1, y2;

    inline int get_dir(int dx, int dy)
    {
        static const int _dir[2][2] = {{0, 3}, {1, 2}};

        return _dir[dx < 0][dy < 0];
    }
    inline bool inRect(node_pointer p)
    {
        return x1 <= p->x1 && x2 >= p->x2 && y1 <= p->y1 && y2 >= p->y2;
    }
    inline bool outRect(node_pointer p)
    {
        return p->x2 <= x1 || p->x1 >= x2 || p->y2 <= y1 || p->y1 >= y2;
    }
    void add(node_pointer p)
    {
        int x0 = (p->x1 + p->x2) / 2, y0 = (p->y1 + p->y2) / 2;

        p->sum += s;
        if (x != x0 || y != y0) {
            add(p->get_p(get_dir(x - x0, y - y0)));
        }
        else {
            p->cnt += s;
        }
    }
    int sum(node_pointer p)
    {
        if (inRect(p)) {
            return p->sum;
        }
        else if (outRect(p)) {
            return 0;
        }
        else {
            int x0 = (p->x1 + p->x2) / 2, y0 = (p->y1 + p->y2) / 2;
            int ret = 0;

            for (int i = 0; i < 4; i++) {
                if (p->p[i] != NULL) {
                    ret += sum(p->p[i]);
                }
            }
            if (x0 >= x1 && x0 < x2 && y0 >= y1 && y0 < y2) {
                ret += p->cnt;
            }

            return ret;
        }
    }
public:
    QuadTree(int xmin, int xmax, int ymin, int ymax)
    {
        root = new node_type(xmin, xmax, ymin, ymax);
    }
    ~QuadTree()
    {
        delete root;
    }
    void insert(int x, int y, int s)
    {
        assert(x >= root->x1 && x < root->x2);
        assert(y >= root->y1 && y < root->y2);

        this->x = x;
        this->y = y;
        this->s = s;
        add(root);
    }
    int query(int xmin, int xmax, int ymin, int ymax)
    {
        this->x1 = xmin;
        this->x2 = xmax;
        this->y1 = ymin;
        this->y2 = ymax;
        return sum(root);
    }
};

int main(void)
{
    static char buf[256];
    char ins;
    int x1, x2, y1, y2, x, y, s;

    while (gets(buf) != NULL) {
        assert(buf[0] == 'I' || buf[0] == 'Q' || buf[0] == 'E');

        QuadTree qt(0, 20002, 0, 20002);

        ins = buf[0];
        while (ins != 'E') {
            gets(buf);
            if (isdigit(buf[0])) {
                if (ins == 'I') {
                    sscanf(buf, "%d%d%d", &x, &y, &s);
                    qt.insert(x, y, s);
                }
                else {
                    sscanf(buf, "%d%d%d%d", &x1, &x2, &y1, &y2);
                    printf("%d\n", qt.query(x1, x2 + 1, y1, y2 + 1));
                }
            }
            else {
                ins = buf[0];
            }
        }
    }
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3043345   2008-08-20 17:15:08     Accepted    3018    C++     00:02.27    4304K   Re:ReJudge

// 2012-09-07 04:01:58 | Accepted | 3018 | C++ | 990 | 4008 | watashi | Source
