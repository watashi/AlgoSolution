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

#define ALLLL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
#define WATASHI_PC

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
#ifndef WATASHI_PC
#define errf(fmt, ...) do { } while (false)
#endif

struct XorAndSum {
  long long maxSum(vector<long long> number);
};

bool test(long long a, int b) {
  return (a >> b) & 1;
}

long long XorAndSum::maxSum(vector<long long> a) {
  int n = a.size(), m = 0;
  for (int i = 63; i >= 0; --i) {
    for (int j = m; j < n; ++j) {
      if (test(a[j], i)) {
        swap(a[j], a[m]);
        break;
      }
    }
    /* m < n !!! */
    if (m < n && test(a[m], i)) {
      for (int j = m + 1; j < n; ++j) {
        if (test(a[j], i)) {
          a[j] ^= a[m];
        }
      }
      ++m;
    }
  }

  long long top = 0;
  for (int i = 0; i < m; ++i) {
    top = max(top, top ^ a[i]);
  }

  long long sum = top * (n - (m - 1));
  for (int i = 1; i < m; ++i) {
    long long cur = top ^ a[i];
    for (int j = i + 1; j < m; ++j) {
      cur = max(cur, cur ^ a[j]);
    }
    sum += cur;
  }

  return sum;
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

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  {
    long long numberARRAY[] = {1LL,0LL};
    vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
    XorAndSum theObject;
    eq(0, theObject.maxSum(number),2LL);
  }
  {
    long long numberARRAY[] = {1LL,2LL,3LL};
    vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
    XorAndSum theObject;
    eq(1, theObject.maxSum(number),8LL);
  }
  {
    long long numberARRAY[] = {0LL,0LL,0LL,0LL,0LL,0LL,0LL,0LL,0LL,0LL};
    vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
    XorAndSum theObject;
    eq(2, theObject.maxSum(number),0LL);
  }
  {
    long long numberARRAY[] = {2LL,3LL,5LL,7LL,11LL,13LL,17LL,19LL};
    vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
    XorAndSum theObject;
    eq(3, theObject.maxSum(number),233LL);
  }
  {
    long long numberARRAY[] = {123456789012345LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL};
    vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
    XorAndSum theObject;
    eq(4, theObject.maxSum(number),1234567890123450LL);
  }
  {
    long long numberARRAY[] = {627LL,674LL,281LL,272LL,289LL,877LL,62LL,122LL,603LL,189LL,615LL};
    vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
    XorAndSum theObject;
    eq(5, theObject.maxSum(number),10742LL);
  }
  {
    long long numberARRAY[] = {557LL};
    vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
    XorAndSum theObject;
    eq(6, theObject.maxSum(number),557LL);
  }

  puts("\033[1;33mPress any key to continue...\033[0m");
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

