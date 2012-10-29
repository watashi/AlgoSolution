import Array;
import Stdio;

class interval {
	int s, e;

	void create(string x) {
		int ss, ee;
		sscanf(x, "%c%d,%d%c", ss, s, e, ee);
		s = s * 2 + (ss == '(');
		e = e * 2 - (ee == ')');
	}
	
	int `<(interval o) {
		return s < o->s;
	}

	int `&(interval o) {
		return !(e < o->s || o->e < s);
	}
}

int main() {
	int n = (int)stdin->gets(), s, e;
	array(interval) a = ({});

	for (int i = 0; i < n; ++i) {
		a += ({interval(stdin->gets())});
	}
	a = sort_array(a);
	for (int i = 0; i < n; ++i) {
		s = a[i]->s;
		e = a[i]->e;
		for (int j = 0; j < i; ++j) {
			if (a[i] & a[j]) {
				e = min(e, a[j]->e);
			}
		}
		for (int j = i + 1; j < n; ++j) {
			if (a[i] & a[j]) {
				s = max(s, a[j]->s);
			}
		}
		if (s > e) {
			write("2");
			return 0;
		}
	}
	write("1");
	return 0;
}