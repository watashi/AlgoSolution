#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
	string name;
	int val[4];
	vector<string> sub;
	bool operator<(const Item& o) const {
		for (int i = 0; i < 3; ++i) {
			if (val[i] != o.val[i]) {
				return val[i] > o.val[i];
			}
		}
		return false;
	}
};

Item ans[3];
vector<int> sum[3];
vector<Item> v[3], w[3];
map<string, Item> mp;

Item& findItemByName(const string& name) {
	vector<Item>::iterator it;
	for (int i = 0; i < 4; ++i) {
		if (i == 3) {
			throw 1;
		}
		it = find_if(v[i].begin(), v[i].end(), [&](const Item& item){return item.name == name;});
		if (it != v[i].end()) {
			break;
		}
	}
	return *it;
}

int main() {
	int n;
	Item item;
	bool slot = false;
	string str;
	map<string, int> c2i = {{"weapon", 0}, {"armor", 1}, {"orb", 2}};
	map<string, int> t2i = {{"gladiator", 0}, {"sentry", 1}, {"physician", 2}};

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> item.name >> str;
		for (int j = 0; j < 4; ++j) {
			cin >> item.val[j];
		}
		if (c2i.count(str) == 0) {
			throw 1;
		}
		v[c2i[str]].push_back(item);
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> item.name >> str;
		for (int j = 0; j < 4; ++j) {
			item.val[j] = 0;
		}
		if (t2i.count(str) == 0) {
			throw 1;
		}
		cin >> item.val[t2i[str]];
		cin >> str;
		findItemByName(str).sub.push_back(item.name);
		mp[item.name] = item;
	}
	
	for (const vector<Item>& vi: v) {
		for (const Item& item: vi) {
			slot |= item.val[3] > (int)item.sub.size();
		}
	}
	// fprintf(stderr, "slot = %s\n", slot ? "YES" : "NO");
	if (slot) {
		for (const pair<string, Item>& p: mp) {
			for (int i = 0; i < 3; ++i) {
				if (p.second.val[i] != 0) {
					w[i].push_back(p.second);
				}
			}
		}
		for (int i = 0; i < 3; ++i) {
			sort(w[i].begin(), w[i].end());
			sum[i] = vector<int>(1, 0);
			for (const Item& item: w[i]) {
				sum[i].push_back(sum[i].back() + item.val[i]);
			}
		}
	} else {
		for (vector<Item>& vi: v) {
			for (Item& item: vi) {
				for (const string& name: item.sub) {
					const Item& jtem = mp[name];
					for (int k = 0; k < 3; ++k) {
						item.val[k] += jtem.val[k];
					}
				}
			}
		}
	}

	vector<int> best(3, -1);
	for (const Item& i: v[0]) {
		for (const Item& j: v[1]) {
			for (const Item& k: v[2]) {
				vector<int> temp = {i.val[0], j.val[1], k.val[2]};
				if (slot) {
					temp[0] += sum[0][min((int)w[0].size(), i.val[3])];
					temp[1] += sum[1][min((int)w[1].size(), j.val[3])];
					temp[2] += sum[2][min((int)w[2].size(), k.val[3])];
				}
	//			printf("%d %d %d\n", temp[0], temp[1], temp[2]);
				if (temp > best) {
	//				puts("GAO");
					best = temp;
					ans[0] = i;
					ans[1] = j;
					ans[2] = k;
				}
			}
		}
	}

	if (slot) {
		for (int i = 0; i < 3; ++i) {
			Item& item = ans[i];
			item.sub.clear();
			for (int j = 0; j < item.val[3] && j < (int)w[i].size(); ++j) {
				item.sub.push_back(w[i][j].name);
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		const Item& item = ans[i];
		cout << item.name << " " << item.sub.size();
		for (const string& str: item.sub) {
			cout << " " << str;
		}
		cout << endl;
	}

	return 0;
}

