/* //第一次使用Trie树，~当然用map写起来容易 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define char2int(ch) ((isdigit(ch))?(ch-'0'+26):(ch-'a'))
struct Prob{
    char ac;
    int sub;
    int time;
};
struct Prob p[9];

void show(char prob,struct Prob *p)
{
    putchar(prob);
    if(p->ac) printf(" %d %.2lf %.2lf\n",p->ac,(double)p->sub/p->ac,(double)p->time/p->ac);
    else printf(" 0\n");
}

struct Team{
    struct Prob p[9];
};
struct Team t[2000];

struct Trie{
    int mark;
    struct Trie *p[36];
};
struct Trie root;
int size;
void init(struct Trie *p)
{
    int i;
    p->mark=-1;
    for(i=0;i<36;i++)
        p->p[i]=NULL;
}
void clear(struct Trie *p)
{
    int i;
    for(i=0;i<36;i++){
        if(p->p[i]==NULL) continue;
        else{
            clear(p->p[i]);
            free(p->p[i]);
        }
    }
}
int find(struct Trie *t,char *p)
{
    int next=char2int(*p);
    if(*p=='\0'){
        if(t->mark!=-1) return t->mark;
        else return t->mark=size++;
    }
    else{
        if(t->p[next]==NULL) init(t->p[next]=(struct Trie*)malloc(sizeof(struct Trie)));
        return find(t->p[next],p+1);
    }
}

void doit(int time,char *team,char prob,char ac)
{
    int tid=find(&root,team);
    int pid=prob-'A';
    if(t[tid].p[pid].ac) return;
    t[tid].p[pid].sub++;
    if(ac=='A'){
        t[tid].p[pid].ac=1;
        p[pid].ac++;
        p[pid].sub+=t[tid].p[pid].sub;
        p[pid].time+=time;
    }
}

int main()
{
    int blank=0,i,n,time;
    char team[6],prob[3],res[3];

    while(scanf("%d",&n)!=EOF){
        if(blank) putchar('\n');
        else blank=1;
        memset(p,0,sizeof(p));
        memset(t,0,sizeof(t));
        size=0;
        init(&root);
        for(i=0;i<n;i++){
            scanf("%d%s%s%s",&time,team,prob,res);
            doit(time,team,*prob,*res);
        }
        clear(&root);
        for(i=0;i<9;i++)
            show('A'+i,&p[i]);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684129 2007-11-24 12:37:06 Accepted 2443 C 00:00.01 612K わたし */

/*
Rank Submit time Run time Run memory Language User
1 2006-03-08 09:35:50 00:00.01 404K C++ ant
2 2006-05-01 22:02:59 00:00.01 404K C++ what0istest
3 2006-03-27 23:56:34 00:00.01 408K C Ivan
4 2006-04-23 20:37:24 00:00.01 408K C++ pencil
5 2007-11-24 12:37:06 00:00.01 612K C わたし
6 2005-09-15 15:42:08 00:00.01 860K C++ andy
7 2006-05-04 15:43:28 00:00.01 1076K C++ ÅÆÇ
8 2005-09-20 22:58:18 00:00.02 392K C foolman
9 2005-11-05 17:09:41 00:00.02 400K C++ nuanran
10 2006-04-23 20:39:14 00:00.02 404K C++ 8600
11 2006-02-11 10:56:35 00:00.02 840K C++ wywcgs
12 2005-09-15 21:54:14 00:00.02 844K C++ Leave me alone
13 2006-12-20 14:54:05 00:00.02 868K C++ *^_^*
14 2007-09-13 14:58:44 00:00.02 1028K C++ terranw
15 2006-05-04 15:43:40 00:00.02 1080K C++ SHiVa
16 2007-08-17 15:27:12 00:00.02 1156K C++ AndyZhau
17 2005-09-25 17:35:09 00:00.02 2764K GPC cqf
18 2006-01-16 18:38:56 00:00.03 416K FPC SpeedStar
19 2006-02-02 18:38:49 00:00.03 852K C++ Invisible Coders United
20 2007-05-09 21:16:57 00:00.03 864K C++ SuperDog
*/

// 2012-09-07 04:56:21 | Accepted | 2443 | C | 0 | 372 | watashi | Source
