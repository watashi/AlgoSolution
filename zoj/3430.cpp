#include <cmath> // auto fix CE
#include <bitset>
#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <string>
#include <cmath> // auto fix CE
#include <cstring>
#include <cmath> // auto fix CE
#include <algorithm>

using namespace std;

std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);

typedef unsigned char char_t;
const int SIGMA=256;
const int ELEMENT_MAX=64*512;

struct TrieGraph{
    struct trie{
        bitset<512> tag;
    //  int tag;
        bool match;
        trie *pre,*child[SIGMA];
        trie():match(false),pre(0),tag(0){memset(child,0,sizeof(child));}
        void* operator new(size_t, void *p){return p;}
    }root,superroot;
    static char storage[ELEMENT_MAX*sizeof(trie)];
    static trie* data;
    static void init(){data=(trie*)storage;}
    TrieGraph::trie* insert(const char_t* s,int n){
        trie* t=&root;
        for(int i=0;i<n;++i){
            char_t c=s[i];
            if(!t->child[c])
                t->child[c]=new((void*)data++) trie;
            t=t->child[c];
        }
        t->match=true;
        return t;
    }
    void build_graph(){
        static trie* Q[ELEMENT_MAX];
        superroot.pre=root.pre=&superroot;
        for(int i=0;i<SIGMA;++i)
            superroot.child[i]=&root;
        int head=0,tail=0;
        Q[tail++]=&root;
        while(head!=tail){
            trie* t=Q[head++];
            t->match|=t->pre->match;
            t->tag|=t->pre->tag;    //
            for(int i=0;i<SIGMA;++i){
                if(t->child[i]){
                    t->child[i]->pre=t->pre->child[i];
                    Q[tail++]=t->child[i];
                }
                else
                    t->child[i]=t->pre->child[i];
            }
        }
    }
    bool match(const char_t* s,int n){
        trie* t=&root;
        for(int i=0;i<n;++i)
            if((t=t->child[s[i]])->match)
                return true;
        return false;
    }
};
char TrieGraph::storage[ELEMENT_MAX*sizeof(trie)];
TrieGraph::trie* TrieGraph::data;

int main() {
    int n, m;
    string s;
    bool mark[1024];
    static char base64[65536];

//  while (scanf("%s", base64) != EOF) {
//      fprintf(stderr, "%d\n", base64_decode(base64).length());
//      printf("%s\n", base64_decode(base64).c_str());
//  }
    while (scanf("%d", &n) != EOF) {
        TrieGraph::init();
        TrieGraph g;
        for (int i = 0; i < n; ++i) {
            scanf("%s", base64);
            s = base64_decode(base64);
        //  printf("%d [%s]\n", s.length(), s.c_str());
            TrieGraph::trie* t = g.insert((const char_t*)s.c_str(), s.length());
            t->tag.set(i);
        //  t->tag = i;
        //  printf("%p %d\n", t, t->tag);
        }
        g.build_graph();

        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            bitset<512> tag;
            scanf("%s", base64);
            s = base64_decode(base64);
            //  printf("%d [%s]\n", s.length(), s.c_str());
            fill(mark, mark + n, false);
            TrieGraph::trie* t = &g.root;
            for (int j = 0; j < (int)s.length(); ++j) {
                t = t->child[(char_t)s[j]];
            //  printf("%p %d\n", t, t->tag);
                tag |= t->tag;
            }
            printf("%d\n", tag.count());
        }
        puts("");
    }

    return 0;
}


/*
   base64.cpp and base64.h

   Copyright (C) 2004-2008 Ren? Nyffenegger

   This source code is provided 'as-is', without any express or implied
   warranty. In no event will the author be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this source code must not be misrepresented; you must not
      claim that you wrote the original source code. If you use this source code
      in a product, an acknowledgment in the product documentation would be
      appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
      misrepresented as being the original source code.

   3. This notice may not be removed or altered from any source distribution.

   Ren? Nyffenegger rene.nyffenegger@adp-gmbh.ch

*/

static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}

std::string base64_decode(std::string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}


//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//379   2010-11-11 14:04:46     Accepted    D   C++     250     35444   watashi@Zodiac  Source

// 2012-09-07 15:54:19 | Accepted | 3430 | C++ | 260 | 35444 | watashi | Source
