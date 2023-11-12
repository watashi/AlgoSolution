class Solution {
public:
  static vector<int>::iterator bsearch(vector<int>::iterator begin, vector<int>::iterator end, int pos) {
    int mask = (1 << pos) - 1;
    return lower_bound(begin, end, (*begin & ~mask) | (1 << pos));
  }

  static bool check(vector<int>::iterator begin1, vector<int>::iterator end1, vector<int>::iterator begin2, vector<int>::iterator end2) {
    return begin1 < end1 && begin2 < end2 && end1 <= begin2 && begin2[0] - end1[-1] <= end1[-1];
  }

  static int gao2(int pos, vector<int>::iterator begin1, vector<int>::iterator end1, vector<int>::iterator begin2, vector<int>::iterator end2) {
    assert(begin1 < end1 && begin2 < end2 && end1 <= begin2);
    if (--pos < 0) {
      return 0;
    }
    auto mid1 = bsearch(begin1, end1, pos);
    auto mid2 = bsearch(begin2, end2, pos);
    int ret = -1;
    if (check(begin1, mid1, mid2, end2)) {
      ret = max(ret, gao2(pos, begin1, mid1, mid2, end2) | (1 << pos));
    }
    if (check(mid1, end1, begin2, mid2)) {
      ret = max(ret, gao2(pos, mid1, end1, begin2, mid2) | (1 << pos));
    }
    if (ret < 0) {
      if (check(begin1, mid1, begin2, mid2)) {
        ret = max(ret, gao2(pos, begin1, mid1, begin2, mid2));
      }
      if (check(mid1, end1, mid2, end2)) {
        ret = max(ret, gao2(pos, mid1, end1, mid2, end2));
      }
    }
    /*
    errf("[%d]:", pos);
    errf("%d, ", vector<int>(begin1, mid1));
    errf("%d, ", vector<int>(mid1, end1));
    errf("%d, ", vector<int>(begin2, mid2));
    errf("%d, ", vector<int>(mid2, end2));
    errf("return = %d\n", ret);
    */
    assert(ret >= 0);
    return ret;
  }

  static int gao(int pos, vector<int>::iterator begin, vector<int>::iterator end) {
    if (--pos < 0 || begin == end) {
      return 0;
    }
    auto mid = bsearch(begin, end, pos);
    if (mid == begin || mid == end) {
      return gao(pos, begin, end);
    }
    if (mid[0] - mid[-1] <= mid[-1]) {
      return gao2(pos, begin, mid, mid, end) | (1 << pos);
    }
    else {
      return max(gao(pos, begin, mid), gao(pos, mid, end));
    }
  }

  int maximumStrongPairXor(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return gao(20, nums.begin(), nums.end());
  }
};
