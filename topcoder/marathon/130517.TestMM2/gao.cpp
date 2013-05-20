#include <map>
#include <cmath>
#include <ctime>
#include <limits>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))

typedef long long llint;

namespace timer {
  const llint MSEC_PER_SEC = 1000000LL;
  const llint TIME_LIMIT = 19500000;

  static timeval tv;
  static llint end, now;

  inline void start() {
    gettimeofday(&tv, NULL);
    end = tv.tv_sec * MSEC_PER_SEC + tv.tv_usec + TIME_LIMIT;
  }

  inline bool timeout() {
    gettimeofday(&tv, NULL);
    now = tv.tv_sec * MSEC_PER_SEC + tv.tv_usec;
    return now > end;
  }
}

const int MAXN = 103;

int sz;
int idx[MAXN][MAXN];

struct StringConnectivity {
  vector<int> placeString(const string& s) {
    sz = (int)nearbyint(sqrt(s.size()));
    return vector<int>();
  }
};

#ifdef __WATASHI__
int main() {
  string s;
  vector<int> ret;

  cin >> s;
  ret = StringConnectivity().placeString(s);
  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); ++i) {
    cout << ret[i] << endl;
  }

  return 0;
}
// vim: ft=cpp.doxygen
#endif
