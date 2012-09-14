// Huffman ~ ^^

#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Node
{
public:
    Node *l, *r;
    int data;
    int cnt;
    Node(int data, int cnt) : data(data), cnt(cnt) {
        l = r = NULL;
    }
    Node(const Node& that) {
        *this = that;
    }
    inline bool operator<(const Node& that) const
    {
        return cnt > that.cnt;
    }
};

char buf[1024];
int cnt[128];
int len[128];

void dfs_clear(Node *p, int l)
{
    if(p -> data != EOF) len[p -> data] = l;
    if(p -> l != NULL) dfs_clear(p -> l, l + 1);
    if(p -> r != NULL) dfs_clear(p -> r, l + 1);
    delete p;
}

int main(void)
{
    while(gets(buf) != NULL && strcmp(buf, "END") != 0) {
        int len0, len1;
        len0 = strlen(buf);
        fill (cnt, cnt + 128, 0);
        for (int i = 0; i < len0; i++)
            ++cnt[buf[i]];
        priority_queue<Node> pq;
        for (int i = 0; i < 128; i++)
            if(cnt[i] > 0) pq.push(Node(i, cnt[i]));
        if(pq.size() == 1) {
            len1 = len0;
            len0 *= 8;
        }
        else {
            len0 *= 8;
            len1 = 0;
            while(pq.size() > 1) {
                Node *l, *r;
                l = new Node(pq.top());
                pq.pop();
                r = new Node(pq.top());
                pq.pop();
                Node p(EOF, l -> cnt + r -> cnt);
                p.l = l;
                p.r = r;
                pq.push(p);
            }
            Node *root = new Node(pq.top());
            pq.pop();
            dfs_clear(root, 0);
            for (int i = 0; i < 128; i++)
                if(cnt[i] > 0) len1 += cnt[i] * len[i];
        }
        printf("%d %d %.1lf\n", len0, len1, (double)len0 / len1);
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2749198 2008-02-12 16:03:05 Accepted 1117 C++ 00:00.00 840K ¤ï¤¿¤·

// 2012-09-07 00:37:52 | Accepted | 1117 | C++ | 0 | 180 | watashi | Source
