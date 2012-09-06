/* // SPLAY_TREE */


#include <stdio.h>
#include <stdlib.h>

typedef struct __splay_node
{
    int reversed, size, deleted;
    struct __splay_node *l, *r, *p;
} node;

void update(node* p)
{
    p->size = 1 - p->deleted;
    if (p->l != NULL) {
        p->size += p->l->size;
    }
    if (p->r != NULL) {
        p->size += p->r->size;
    }
}

void zig(node* p)
{
    node* t = p->r;

    p->r = p->p;
    p->p = p->p->p;
    p->r->p = p;
    p->r->l = t;
    if (t != NULL) {
        p->r->l->p = p->r;
    }
    if (p->p != NULL) {
        if (p->p->l == p->r) {
            p->p->l = p;
        }
        else {
            p->p->r = p;
        }
    }
    update(p->r);
    update(p);
}

void zag(node* p)
{
    node* t = p->l;

    p->l = p->p;
    p->p = p->p->p;
    p->l->p = p;
    p->l->r = t;
    if (t != NULL) {
        p->l->r->p = p->l;
    }
    if (p->p != NULL) {
        if (p->p->l == p->l) {
            p->p->l = p;
        }
        else {
            p->p->r = p;
        }
    }
    update(p->l);
    update(p);
}

void zigzig(node* p)
{
    zig(p->p);
    zig(p);
}

void zigzag(node* p)
{
    zig(p);
    zag(p);
}

void zagzig(node* p)
{
    zag(p);
    zig(p);
}

void zagzag(node* p)
{
    zag(p->p);
    zag(p);
}



void reverse(node *p)
{
    node* t;

    if (p == NULL || p->reversed == 0) {
        return;
    }

    t = p->l;
    p->l = p->r;
    p->r = t;
    if (p->l != NULL) {
        p->l->reversed = 1 - p->l->reversed;
    }
    if (p->r != NULL) {
        p->r->reversed = 1 - p->r->reversed;
    }
    p->reversed = 0;
}

void splay(node *p)
{
    while (p->p != NULL) {
        reverse(p->p->p);
        reverse(p->p);
        reverse(p);
        if (p->p->p == NULL) {
            if (p == p->p->l) {
                zig(p);
            }
            else {
                zag(p);
            }
        }
        else if (p->p == p->p->p->l) {
            if (p == p->p->l) {
                zigzig(p);
            }
            else {
                zagzig(p);
            }
        }
        else {
            if (p == p->p->l) {
                zigzag(p);
            }
            else {
                zagzag(p);
            }
        }
    }
}

/************************************************************************/

int gao(node *p)
{
    int ret;

    splay(p);
    if (p->l != NULL) {
        p->l->reversed = 1 - p->l->reversed;
        ret = p->l->size;
    }
    else {
        ret = 0;
    }
    p->deleted = 1;
    --p->size;

    return ret;
}

/************************************************************************/

#define MAXN 100001

node splay_node[MAXN];

void build_splay_tree(int n, const int a[])
{
    int i;

    for (i = 0; i < n; i++) {
        splay_node[a[i]].reversed = splay_node[a[i]].deleted = 0;
        splay_node[a[i]].size = i + 1;
        splay_node[a[i]].p = (i == n - 1) ? NULL : &splay_node[a[i + 1]];
        splay_node[a[i]].l = (i == 0) ? NULL : &splay_node[a[i - 1]];
        splay_node[a[i]].r = NULL;
    }
}

int a[MAXN], b[MAXN], p[MAXN];

int cmp(const void* lhs, const void* rhs)
{
    int lv = *(int *)lhs, rv = *(int *)rhs;

    if (a[lv] != a[rv]) {
        return (a[lv] < a[rv]) ? -1 : 1;
    }
    else {
        return (lv < rv) ? -1 : 1;
    }
}

int main(void)
{
    int i, n;

    while (scanf("%d", &n) != EOF && n > 0) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = i;
        }
        qsort((void*)b, n, sizeof(int), cmp);
        for (i = 0; i < n; i++) {
            p[b[i]] = i;
        }
        build_splay_tree(n, p);
        for (i = 0; i < n; i++) {
            if (i > 0) {
                putchar(' ');
            }
            printf("%d", i + 1 + gao(splay_node + i));
        }
        putchar('\n');
    }

    return 0;
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //3018053 2008-08-02 14:41:03 Accepted 2985 C 00:00.82 3996K Re:ReJudge */
/* // */


/*
Rank Submit time Run time Run memory Language User
1 2008-08-02 01:37:15 00:00.75 3576K C++ awpris
2 2008-08-02 14:41:03 00:00.82 3996K C Re:ReJudge
3 2008-07-29 14:07:16 00:00.84 7552K C++ long1
*/

// 2012-09-07 01:52:27 | Accepted | 2985 | C | 390 | 4068 | watashi | Source
