#include <map>
#include <cstdio>
#include <string>
#include <numeric>

using namespace std;

const int MAXN = 17;
const char* atomlist[] = {"<null>", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt"};

map<string, int> atommap;

void init() {
	for (int i = 1; i < (int)(sizeof(atomlist) / sizeof(atomlist[0])); ++i) {
		atommap[atomlist[i]] = i;
	}
}

int a[MAXN], b[MAXN], c[1 << MAXN], d[MAXN];
bool done[MAXN][1 << MAXN];

void gao(int n, int m) {
	if (n == 0) {
		if (m == 0) {
			throw 1;
		}
	} else {
		--n;
		if (done[n][m]) {	// TLE88
			return;
		} else {
			done[n][m] = true;
		}
		for (int s = m; s > 0; s = (s - 1) & m) {
			if (b[n] == c[s]) {
				d[n] = s;
				gao(n, m ^ s);
			}
		}
	}
}

int getatom() {
	static char buf[80];
	scanf("%s", buf);
	return atommap[buf];
}

int main() {
	int n, m, t;
	
	init();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		a[i] = getatom();
	}
	for (int i = 0; i < m; ++i) {
		b[i] = getatom();
	}
	c[0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		t = __builtin_ctz(i);
		c[i] = c[i ^ (1 << t)] + a[t];
	}
	
	if (accumulate(a, a + n, 0) != accumulate(b, b + m, 0)) {
		puts("NO");
	} else {
		try {
			gao(m, (1 << n) - 1);
			puts("NO");
		} catch (...) {
			puts("YES");
			for (int i = 0; i < m; ++i) {
				bool first = true;
				for (int j = 0; j < n; ++j) {
					if (d[i] & (1 << j)) {
						if (first) {
							first = false;
						} else {
							putchar('+');
						}
						printf("%s", atomlist[a[j]]);
					}
				}
				printf("->%s\n", atomlist[b[i]]);
			}
		}
	}

	return 0;
}

