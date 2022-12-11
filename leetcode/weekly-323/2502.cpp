class Allocator {
public:
  Allocator(int n) {
    unused.emplace(0, n);
  }

  int allocate(int size, int mID) {
    for (auto i : unused) {
      if (i.second >= size) {
        pair<int, int> p(i.first + size, i.second - size);
        unused.erase(i);
        used[mID].emplace(i.first, size);
        if (p.second > 0) {
          unused.insert(p);
        }
        return i.first;
      }
    }
    return -1;
  }

  int free(int mID) {
    int ret = 0;
    auto todo = used[mID];
    used.erase(mID);
    for (auto i : todo) {
      auto it = unused.lower_bound(make_pair(i.first, 0));
      ret += i.second;
      if (it != unused.end() && it->first == i.first + i.second) {
        i.second += it->second;
        unused.erase(it);
      }
      it = unused.lower_bound(make_pair(i.first, 0));
      if (it != unused.begin()) {
        --it;
        if (it->first + it->second == i.first) {
          i.first = it->first;
          i.second += it->second;
          unused.erase(it);
        }
      }
      unused.insert(i);
    }
    return ret;
  }

  map<int, set<pair<int, int>>> used;
  set<pair<int, int>> unused;
};
