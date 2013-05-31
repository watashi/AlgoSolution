#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdarg>
#include <algorithm>

using namespace std;

const int BUFLEN = 4096;

int sprintf(string& str, const char* fmt, ...) {
  static char buf[BUFLEN];
  va_list args;
  va_start(args, fmt);
  int ret = vsprintf(buf, fmt, args);
  va_end(args);
  str += buf;
  return ret;
}

template<typename T>
struct Base {
  int valid;
  string name;

  static vector<T*> _v;
  static map<string, T*> _mp;

  Base(const string& name): valid(false), name(name) {
  }

  const char* c_str() const {
    return name.c_str();
  }

  static void clear() {
    for (int i = 0; i < (int)_v.size(); ++i) {
      delete _v[i];
    }
    _v.clear();
    _mp.clear();
  }

  static T* at(int i) {
    return i < (int)_v.size() ? _v[i] : NULL;
  }

  static T* get(const string& name) {
    if (_mp.count(name) > 0) {
      return _mp[name];
    } else {
      T* p = new T(name);
      _v.push_back(p);
      _mp[name] = p;
      return p;
    }
  }
};

#define DECL(T) \
  struct T;\
  template<> vector<T*> Base<T>::_v = vector<T*>();\
  template<> map<string, T*> Base<T>::_mp = map<string, T*>()

DECL(Item);
DECL(Char);
DECL(Room);

struct Item: Base<Item> {
  bool used;
  vector<Char*> vc;
  vector<Room*> vr;

  Item(const string& name): Base<Item>(name), used(false) { }
  void gao(Room*& cur, string& buf);
};

struct Char: Base<Char> {
  enum Type {
    CHARACTOR = 0,
    OBJECT = 1,
  } type;
  Room* r;
  vector<Item*> from;
  vector<Item*> to;
  set<Item*> rem;

  Char(const string& name): Base<Char>(name) { }
  void gao(Room*& cur, string& buf);
};

struct Room: Base<Room> {
  bool win;
  vector<Char*> vc;
  vector<Item*> vi;
  vector<Item*> vk;

  Room(const string& name): Base<Room>(name), win(false) { }
  bool move(Room*& cur, string& buf);
  void gao(Room*& cur, string& buf);
};

bool Room::move(Room*& cur, string& buf) {
  map<Room*, pair<Room*, Item*> > mp;
  queue<Room*> q;

  q.push(cur);
  mp[cur];
  while (!q.empty() && mp.count(this) == 0) {
    Room* p = q.front();
    q.pop();
    for (int i = 0; i < (int)p->vk.size(); ++i) {
      Item *k = p->vk[i];
      Room* pp = k->vr[p != k->vr[0] ? 0 : 1];
      if (k->valid && mp.count(pp) == 0) {
        q.push(pp);
        mp[pp] = make_pair(p, k);
      }
    }
  }

  if (mp.count(this) > 0) {
    vector<pair<Room*, Item*> > v;
    for (Room* p = this; p != cur; p = mp[p].first) {
      v.push_back(make_pair(p, mp[p].second));
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
      if (!v[i].second->used) {
        v[i].second->used = true;
        sprintf(buf, "open door to %s\n", v[i].first->c_str());
      }
      sprintf(buf, "go to %s\n", v[i].first->c_str());
    }
    cur = this;
    return true;
  } else {
    return false;
  }
}

void Item::gao(Room*& cur, string& buf) {
  if (!valid) {
    valid = true;
    for (int i = 0; i < (int)vc.size(); ++i) {
      vc[i]->rem.erase(this);
      vc[i]->gao(cur, buf);
    }
    for (int i = 0; i < (int)vr.size(); ++i) {
      vr[i]->gao(cur, buf);
    }
  }
}

void Char::gao(Room*& cur, string& buf) {
  if (valid || !rem.empty() || !r->move(cur, buf)) {
    return;
  } else {
    valid = true;
  }
  if (type == CHARACTOR) {
    sprintf(buf, "talk to %s\ngive", c_str());
  } else {
    sprintf(buf, "use");
  }
  for (int i = 0; i < (int)from.size(); ++i) {
    sprintf(buf, "%s %s",
      i == 0 ? "" : i == (int)from.size() - 1 ? " and" : ",",
      from[i]->c_str());
  }
  sprintf(buf, " %s %s\ntake", type == CHARACTOR ? "to" : "on", c_str());
  for (int i = 0; i < (int)to.size(); ++i) {
    sprintf(buf, "%s %s",
      i == 0 ? "" : i == (int)to.size() - 1 ? " and" : ",",
      to[i]->c_str());
  }
  sprintf(buf, " from %s\n", c_str());
  for (int i = 0; i < (int)to.size(); ++i) {
    to[i]->gao(cur, buf);
  }
}

void Room::gao(Room*& cur, string& buf) {
  if (valid || !move(cur, buf)) {
    return;
  } else {
    valid = true;
  }
  if (win) {
    sprintf(buf, "save princess\n");
    throw 1;
  }
  for (int i = 0; i < (int)vi.size(); ++i) {
    sprintf(buf, "pick %s\n", vi[i]->c_str());
  }
  for (int i = 0; i < (int)vc.size(); ++i) {
    vc[i]->gao(cur, buf);
  }
  for (int i = 0; i < (int)vi.size(); ++i) {
    vi[i]->gao(cur, buf);
  }
  for (int i = 0; i < (int)vk.size(); ++i) {
    for (int j = 0; j < (int)vk[i]->vr.size(); ++j) {
      vk[i]->vr[j]->gao(cur, buf);
    }
  }
}

inline string getName() {
  static char buf[BUFLEN];
  buf[0] = '\0';
  scanf(" %[^,\n]", buf);
  string ret = buf;
  while (!ret.empty() && isspace(*ret.rbegin())) {
    ret.erase(ret.end() - 1);
  }
  return ret;
}

inline Room* getRoom() {
  return Room::get(getName());
}

inline Item* getItem() {
  return Item::get(getName());
}

inline vector<Item*> getItemList() {
  vector<Item*> ret;
  do {
    ret.push_back(getItem());
  } while (getchar() != '\n');
  return ret;
}

inline Char* getChar(Room* r, Char::Type type) {
  Char* p = Char::get(getName());
  p->type = type;
  p->r = r;
  r->vc.push_back(p);
  p->from = getItemList();
  p->to = getItemList();
  for (int i = 0; i < (int)p->from.size(); ++i) {
    Item* q = p->from[i];
    p->rem.insert(q);
    q->vc.push_back(p);
  }
  return p;
}

int main() {
  int n, m, a, b;
  Room *from, *to;
  string ans;

#ifndef __WATASHI__
  freopen("quest.in", "r", stdin);
  freopen("quest.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    getRoom();
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    Item* key = getItem();
    --a;
    --b;
    key->vr.push_back(Room::at(a));
    key->vr.push_back(Room::at(b));
    Room::at(a)->vk.push_back(key);
    Room::at(b)->vk.push_back(key);
  }
  for (int i = 0; i < n; ++i) {
    Room* r = Room::at(i);
    int nc, no, ni;
    scanf("%d%d%d", &nc, &no, &ni);
    for (int j = 0; j < nc; ++j) {
      getChar(r, Char::CHARACTOR);
    }
    for (int j = 0; j < no; ++j) {
      getChar(r, Char::OBJECT);
    }
    for (int j = 0; j < ni; ++j) {
      r->vi.push_back(getItem());
    }
  }

  from = getRoom();
  to = getRoom();
  ans = "";
  to->win = true;
  try {
    from->gao(from, ans);
    puts("dead princess");
  } catch (...) {
    printf("%s", ans.c_str());
  }

  Item::clear();
  Char::clear();
  Room::clear();

  return 0;
}
