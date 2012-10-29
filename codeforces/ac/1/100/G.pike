class album {
	string name;
	int year;

	void create(string n, int y) {
		name = n;
		year = y;
	}

	int `<(album o) {
		if (year != o->year) {
			return year < o->year;
		} else {
			return name > o->name;
		}
	}
}

int main() {
	constant in = Stdio.stdin;
	int n = (int)in->gets();
	mapping(string:int) b = ([]);
	
	for (int i = 0; i < n; ++i) {
		array(string) t = in->gets() / " ";
		b[t[0]] = max(b[t[0]], (int)t[1]);
	}

	int m = (int)in->gets();
	array(album) a = ({});

	a->push(0);
	for (int i = 0; i < m; ++i) {
		string s = in->gets();
		a += ({album(s, b[s])});
	}
	a = Array.sort_array(a);
	write(a[0]->name);

	return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669429 	Sep 5, 2011 5:50:44 PM 	watashi 	100G - Name the album 	Pike 	Accepted 	380 ms 	13800 KB 
