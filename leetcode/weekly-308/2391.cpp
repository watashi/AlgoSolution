class Solution {
public:
  int garbageCollection(vector<string>& v, vector<int>& travel) {
    int m = 0, p = 0, g = 0;
    int ret = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      ret += v[i].size();
      for (char c : v[i]) {
        switch (c) {
        case 'M': m = i; break;
        case 'P': p = i; break;
        case 'G': g = i; break;
        }
      }
    }
    for (int i : {m, p, g}) {
      ret += accumulate(travel.begin(), travel.begin() + i, 0);
    }
    return ret;
  }
};
