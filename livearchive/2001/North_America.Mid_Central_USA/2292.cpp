#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Wnd {
	static char buf[1024][1024];
	const char* const p;
	const char* q;
	char t[64];
	int n, l[64], r[64], w[64], h[64];

	Wnd(const char* p) : p(strdup(p)) {
	}

	~Wnd() {
		delete p;
	}

	int _relax() {
		int m = n;
		t[n++] = *q++;
		if (t[m] == '-' || t[m] == '|') {
			l[m] = _relax();
			r[m] = _relax();
			if (t[m] == '-') {
				w[m] = max(w[l[m]], w[r[m]]);
				h[m] = h[l[m]] + h[r[m]];
			} else {
				w[m] = w[l[m]] + w[r[m]];
				h[m] = max(h[l[m]], h[r[m]]);
			}
		} else {
			l[m] = r[m] = -1;
			w[m] = h[m] = 2;
		}
		return m;
	}

	void relax() {
		q = p;
		n = 0;
		_relax();
	}

	void _render(int m, int x, int y) {
		if (t[m] == '-') {
			int hh = h[l[m]] + h[r[m]];
			w[l[m]] = w[m];
			w[r[m]] = w[m];
			h[l[m]] = (h[m] * h[l[m]] + hh - 1) / hh;
			h[r[m]] = (h[m] * h[r[m]]) / hh;
			buf[x + h[l[m]]][y] = buf[x + h[l[m]]][y + w[m]] = '*';
			for (int j = 1; j < w[m]; ++j) {
				buf[x + h[l[m]]][y + j] = '-';
			}
			_render(l[m], x, y);
			_render(r[m], x + h[l[m]], y);
		} else if (t[m] == '|') {
			int ww = w[l[m]] + w[r[m]];
			w[l[m]] = (w[m] * w[l[m]] + ww - 1) / ww;
			w[r[m]] = (w[m] * w[r[m]]) / ww;
			h[l[m]] = h[m];
			h[r[m]] = h[m];
			buf[x][y + w[l[m]]] = buf[x + h[m]][y + w[l[m]]] = '*';
			for (int i = 1; i < h[m]; ++i) {
				buf[x + i][y + w[l[m]]] = '|';
			}
			_render(l[m], x, y);
			_render(r[m], x, y + w[l[m]]);
		} else {
			buf[x][y] = t[m];
		}
	}

	void render() {
		buf[0][0] = buf[0][w[0]] = buf[h[0]][0] = buf[h[0]][w[0]] = '*';
		buf[0][w[0] + 1] = buf[h[0]][w[0] + 1] = '\0';
		for (int i = 1; i < h[0]; ++i) {
			buf[i][0] = buf[i][w[0]] = '|';
			buf[i][w[0] + 1] = '\0';
		}
		for (int j = 1; j < w[0]; ++j) {
			buf[0][j] = buf[h[0]][j] = '-';
		}
		for (int i = 1; i < h[0]; ++i) {
			for (int j = 1; j < w[0]; ++j) {
				buf[i][j] = ' ';
			}
		}
		_render(0, 0, 0);
		for (int i = 0; i <= h[0]; ++i) {
			puts(buf[i]);
		}
	}
};

char Wnd::buf[1024][1024];

int main() {
	int re;
	char buf[4096];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%s", buf);
		Wnd wnd(buf);
		wnd.relax();
		printf("%d\n", ri);
		wnd.render();
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806225 	2292 	Split Windows 	Accepted 	C++ 	0.012 	2011-05-24 10:14:12
/*
id => 1174062
pid => 2292
pname => Split Windows
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:17:37
*/
