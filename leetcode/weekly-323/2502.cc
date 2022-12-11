class Allocator {
public:
  Allocator(int n): unused(n, true) {
  }

  int allocate(int size, int mID) {
    int c = 0;
    for (int i = 0; i < (int)unused.size(); ++i) {
      if (!unused[i]) {
        c = 0;
        continue;
      }
      if (++c == size) {
        int l = i + 1 - size, r = l + size;
        fill(unused.begin() + l, unused.begin() + r, false);
        used[mID].emplace_back(l, r);
        return l;
      }
    }
    return -1;
  }

  int free(int mID) {
    int ret = 0;
    for (const auto& i: used[mID]) {
      ret += i.second - i.first;
      fill(unused.begin() + i.first, unused.begin() + i.second, true);
    }
    used.erase(mID);
    return ret;
  }

  map<int, vector<pair<int, int>>> used;
  vector<bool> unused;
};
