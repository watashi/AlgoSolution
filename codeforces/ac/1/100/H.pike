string read() {
	return Stdio.stdin->gets();
}

array(array(string)) a;

string get(int i, int j) {
	return 0 <= i && i < 10 && 0 <= j && j < 10 ? a[i][j] : "0";
}

int main() {
	int re = (int)read();
	int x, y, z, dx, dy;

	for (int ri = 1; ri <= re; ++ri) {
		a = ({});
		for (int i = 0; i < 10; ++i) {
			a += ({read() / 1});
		}

		mapping(int:int) m = ([]);
		
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (get(i, j) != "*") {
					continue;
				}
				if (get(i, j + 1) == "*") {
					dx = 0;
					dy = 1;
				} else {
					dx = 1;
					dy = 0;
				}
				x = i;
				y = j;
				z = 0;
				while (get(x, y) != "0") {
					a[x][y] = "#";
					x += dx;
					y += dy;
					++z;
				}
				++m[z];
				for (int k = -1; k <= z; ++k) {
					for (int l = -1; l <= 1; l += 2) {
						if (get(i + k * dx + l * dy, j + k * dy + l * dx) != "0") {
							++m[0];
						}
					}
				}
			}
		}
		write(equal(m, ([1:4, 2:3, 3:2, 4:1])) ? "YES\n" : "NO\n");
		read();
	}

	return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669538 	Sep 5, 2011 6:50:43 PM 	watashi 	100H - Battleship 	Pike 	Accepted 	110 ms 	6500 KB 
