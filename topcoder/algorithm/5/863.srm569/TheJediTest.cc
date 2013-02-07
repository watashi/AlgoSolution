#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
  errf("{");
  FOR(i, v.size()) {
    errf(fmt, v[i]);
  }
  errf("}\n");
}
// TODO
/// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct TheJediTest {
  int minimumSupervisors(vector <int> students, int K);
};

inline bool test(int i, int j) {
  return ((i >> j) & 1) != 0;
}

int TheJediTest::minimumSupervisors(vector <int> stu, int m) {
  int n = stu.size();
  int ans = accumulate(ALL(stu), 0);
  stu.push_back(0);
  FOR (i, 1 << (n - 1)) {
    int rem = 0, cmp = 0;
    // printf("%d\n", i);
    FOR (j, n) {
      int tmp = stu[j] + rem;
      // printf(" %d\n", j);
      if (test(i, j)) {
        cmp += tmp / m;
        rem = tmp % m;
        if (rem > stu[j]) {
          rem = rem - m;
          if (stu[j + 1] + rem >= 0) {
            ++cmp;
          } else {
            goto NEXT;
          }
        }
      } else {
        tmp += stu[j + 1];
        rem = -stu[j + 1];
        cmp += (tmp + m - 1) / m;
      }
    }
    ans = min(ans, cmp);
NEXT:
    continue;
  }
  return ans;
}

/// BEGIN CUT HERE
// TODO
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << "{";
  FOR(i, v.size()) {
    os << "\"" << v[i] << "\",";
  }
  os << "}";

  return os;
}

vector<bool> __eq__;

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    __eq__.push_back(true);
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    __eq__.push_back(false);
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

      {
        int studentsARRAY[] = {3, 6, 3};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(0, theObject.minimumSupervisors(students, 4),3);
    }
    {
        int studentsARRAY[] = {1, 1, 1, 1};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(1, theObject.minimumSupervisors(students, 4),2);
    }
    {
        int studentsARRAY[] = {0, 0, 0, 0};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(2, theObject.minimumSupervisors(students, 12345),0);
    }
    {
        int studentsARRAY[] = {15, 0, 13, 4, 29, 6, 2};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(3, theObject.minimumSupervisors(students, 7),10);
    }
    {
        int studentsARRAY[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(4, theObject.minimumSupervisors(students, 114),102138);
    }

  int __pass__ = count(ALL(__eq__), true);
  int __fail__ = count(ALL(__eq__), false);
  if (__fail__ == 0) {
    errf("\033[1;32mAll %d Passed\033[0m\n", __pass__);
  } else if (__pass__ == 0) {
    errf("\033[1;31mAll %d Failed\033[0m\n", __fail__);
  } else {
    errf("\033[1;31m%d Passed; %d Failed\033[0m\n", __pass__, __fail__);
    if (__eq__[0]) {
      errf("\033[1;31mDid you reset global variables?\033[0m\n");
    }
  }
  errf("\033[1;33mPress any key to continue...\033[0m\n");
  getchar();

  return 0;
}

/*
 * __builtin_popcount __builtin_ctz make_pair
 * priority_queue
 * push_back
 * first second iterator const_iterator
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE
