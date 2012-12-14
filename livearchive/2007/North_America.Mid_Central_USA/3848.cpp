#include <vector>
#include <iostream>
using namespace std;

class Slink
{
private:
	// data
	static const int SIZE = 22;
	int illegalRef;
	int n, m;
	int mark;
	bool mk[SIZE][SIZE];
	int mp[SIZE][SIZE];
	bool vr[SIZE][SIZE];
	int eg[SIZE][SIZE][2]; // 0 for South, 1 for East

	// Cells
	inline int& CN(int x, int y) { return eg[x][y][1]; }
	inline int& CS(int x, int y) { return eg[x + 1][y][1]; }
	inline int& CW(int x, int y) { return eg[x][y][0]; }
	inline int& CE(int x, int y) { return eg[x][y + 1][0]; }

	// Vertex // Vertex is the lefttop corner of Cell
	inline int& VN(int x, int y) { if(x == 0) return illegalRef; return eg[x - 1][y][0]; }
	inline int& VS(int x, int y) { if(x == n) return illegalRef; return eg[x][y][0]; }
	inline int& VW(int x, int y) { if(y == 0) return illegalRef; return eg[x][y - 1][1]; }
	inline int& VE(int x, int y) { if(y == m) return illegalRef; return eg[x][y][1]; }

	// rule 0 - case 1, case 6, case 7
	inline void rule0()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if(mp[i][j] == 0)
					CN(i, j) = CS(i, j) = CW(i, j) = CE(i, j) = -1;
				else if(mp[i][j] == 3) {
					if(i && mp[i - 1][j] == 3)
						CN(i - 1, j) = CN(i, j) = CS(i, j) = 1;
					else if(j && mp[i][j - 1] == 3)
						CW(i, j - 1) = CW(i, j) = CE(i, j) = 1;
					else if(i && j && mp[i - 1][j - 1] == 3)
						CN(i - 1, j - 1) = CS(i, j) = CW(i - 1, j - 1) = CE(i, j) = 1;
					else if(i && j + 1 < m && mp[i - 1][j + 1] == 3)
						CN(i - 1, j + 1) = CS(i, j) = CW(i, j) = CE(i - 1, j + 1) = 1;
				}
			}
	}

	// rule 1 - case 2 - 5 (x, y) is cell
	inline void rule1(const int x, const int y)
	{
		if(mk[x][y]) return;
		int neg = 0, pos = 0, todo;
		switch(CN(x, y)) { case -1: ++neg; break; case 1: ++pos; break; }
		switch(CS(x, y)) { case -1: ++neg; break; case 1: ++pos; break; }
		switch(CW(x, y)) { case -1: ++neg; break; case 1: ++pos; break; }
		switch(CE(x, y)) { case -1: ++neg; break; case 1: ++pos; break; }
		if(pos == mp[x][y]) todo = -1;
		else if(neg == 4 - mp[x][y]) todo = 1;
		else return;
		if(CN(x, y) == 0) CN(x, y) = todo;
		if(CS(x, y) == 0) CS(x, y) = todo;
		if(CW(x, y) == 0) CW(x, y) = todo;
		if(CE(x, y) == 0) CE(x, y) = todo;
		mk[x][y] = true;
		--mark;
	}

	// rule 2 - case 8 - 10 (x, y) is vertex
	inline void rule2(const int x, const int y)
	{
		if(vr[x][y]) return;
		int zero = 0, edge = 0, todo;
		switch(VN(x, y)) { case 0: ++zero; break; case 1: ++edge; break; }
		switch(VS(x, y)) { case 0: ++zero; break; case 1: ++edge; break; }
		switch(VW(x, y)) { case 0: ++zero; break; case 1: ++edge; break; }
		switch(VE(x, y)) { case 0: ++zero; break; case 1: ++edge; break; }
		if(edge == 2) todo = -1;
		else if(zero == 1) {
			if(edge == 0) todo = -1;
			else if(edge == 1) todo = 1;
			else return;
		}
		else return;
		if(VN(x, y) == 0) VN(x, y) = todo;
		if(VS(x, y) == 0) VS(x, y) = todo;
		if(VW(x, y) == 0) VW(x, y) = todo;
		if(VE(x, y) == 0) VE(x, y) = todo;
		vr[x][y] = true;
	}

	// rule 3 - case 11, case 13, case 14, case 17 (x, y) is vertex
	inline void rule3(const int x, const int y)
	{
		if(x && y) { // lefttop
			if(mp[x - 1][y - 1] == 1) { // case 13, case 17
				if(vr[x][y] == 0 && VS(x, y) == -1 && VE(x, y) == -1) { // case 13
					VN(x, y) = -1;
					VW(x, y) = -1;
					vr[x][y] = true;
				}
				else if(VS(x, y) == -1 && VE(x, y) == 1 || VS(x, y) == 1 && VE(x, y) == -1) { // case 17
					CN(x - 1, y - 1) = -1;
					CW(x - 1, y - 1) = -1;
				}
			}
			else if(mp[x - 1][y - 1] == 3) { // case 11, case 14
				if(vr[x][y] == 0 && VS(x, y) == -1 && VE(x, y) == -1) { // case 11
					VN(x, y) = 1;
					VW(x, y) = 1;
					vr[x][y] = true;
				}
				else if(VS(x, y) == -1 && VE(x, y) == 1 || VS(x, y) == 1 && VE(x, y) == -1) { // case 14
					CN(x - 1, y - 1) = 1;
					CW(x - 1, y - 1) = 1;
				}
			}
		}
		if(x && y + 1 < m) { // righttop
			if(mp[x - 1][y] == 1) {
				if(vr[x][y] == 0 && VS(x, y) == -1 && VW(x, y) == -1) {
					VN(x, y) = -1;
					VE(x, y) = -1;
					vr[x][y] = true;
				}
				else if(VS(x, y) == -1 && VW(x, y) == 1 || VS(x, y) == 1 && VW(x, y) == -1) {
					CN(x - 1, y) = -1;
					CE(x - 1, y) = -1;
				}
			}
			else if(mp[x - 1][y] == 3) {
				if(vr[x][y] == 0 && VS(x, y) == -1 && VW(x, y) == -1) {
					VN(x, y) = 1;
					VE(x, y) = 1;
					vr[x][y] = true;
				}
				else if(VS(x, y) == -1 && VW(x, y) == 1 || VS(x, y) == 1 && VW(x, y) == -1) {
					CN(x - 1, y) = 1;
					CE(x - 1, y) = 1;
				}
			}
		}
		if(x + 1 < n && y) { // leftbottom
			if(mp[x][y - 1] == 1) {
				if(vr[x][y] == 0 && VN(x, y) == -1 && VE(x, y) == -1) {
					VS(x, y) = -1;
					VW(x, y) = -1;
					vr[x][y] = true;
				}
				else if(VN(x, y) == -1 && VE(x, y) == 1 || VN(x, y) == 1 && VE(x, y) == -1) {
					CS(x, y - 1) = -1;
					CW(x, y - 1) = -1;
				}
			}
			else if(mp[x][y - 1] == 3) {
				if(vr[x][y] == 0 && VN(x, y) == -1 && VE(x, y) == -1) {
					VS(x, y) = 1;
					VW(x, y) = 1;
					vr[x][y] = true;
				}
				else if(VN(x, y) == -1 && VE(x, y) == 1 || VN(x, y) == 1 && VE(x, y) == -1) {
					CS(x, y - 1) = 1;
					CW(x, y - 1) = 1;
				}				
			}
		}
		if(x + 1 < n && y + 1 < m) { // rightbottom
			if(mp[x][y] == 1) {
				if(vr[x][y] == 0 && VN(x, y) == -1 && VW(x, y) == -1) {
					VS(x, y) = -1;
					VE(x, y) = -1;
					vr[x][y] = true;
				}
				else if(VN(x, y) == -1 && VW(x, y) == 1 || VN(x, y) == 1 && VW(x, y) == -1) {
					CS(x, y) = -1;
					CE(x, y) = -1;
				}
			}
			else if(mp[x][y] == 3) {
				if(vr[x][y] == 0 && VN(x, y) == -1 && VW(x, y) == -1) {
					VS(x, y) = 1;
					VE(x, y) = 1;
					vr[x][y] = true;
				}
				else if(VN(x, y) == -1 && VW(x, y) == 1 || VN(x, y) == 1 && VW(x, y) == -1) {
					CS(x, y) = 1;
					CE(x, y) = 1;
				}
			}
		}
	}

	// rule 4 - case 15 (x, y) is cell
	inline void rule4(const int x, const int y)
	{
		if(mp[x][y] != 3) return;
		if(x && y && mp[x - 1][y - 1] == 1 && VS(x + 1, y + 1) == -1 && VE(x + 1, y + 1) == -1)
			CN(x - 1, y - 1) = CW(x - 1, y - 1) = -1;
		if(x && y + 1 < m && mp[x - 1][y + 1] == 1 && VS(x + 1, y) == -1 && VW(x + 1, y) == -1)
			CN(x - 1, y + 1) = CE(x - 1, y + 1) = -1;
		if(x + 1 < n && y && mp[x + 1][y - 1] == 1 && VN(x, y + 1) == -1 && VE(x, y + 1) == -1)
			CS(x + 1, y - 1) = CW(x + 1, y - 1) = -1;
		if(x + 1 < n && y + 1 < m && mp[x + 1][y + 1] == 1 && VN(x, y) == -1 && VW(x, y) == -1)
			CS(x + 1, y + 1) = CE(x + 1, y + 1) = -1;
	}

	// rule 5 - case 12, case 16 (x, y) is cell
	inline void rule5(const int x, const int y)
	{
		if(mp[x][y] != 2) return;
		// case 12
		if(VN(x, y) == -1 && VW(x, y) == -1) {
			if(VN(x, y + 1) == -1 && VE(x, y + 1) == 0) VE(x, y + 1) = 1;
			if(VN(x, y + 1) == 0 && VE(x, y + 1) == -1) VN(x, y + 1) = 1;
			if(VS(x + 1, y) == -1 && VW(x + 1, y) == 0) VW(x + 1, y) = 1;
			if(VS(x + 1, y) == 0 && VW(x + 1, y) == -1) VS(x + 1, y) = 1;
		}
		if(VN(x, y + 1) == -1 && VE(x, y + 1) == -1) {
			if(VN(x, y) == -1 && VW(x, y) == 0) VW(x, y) = 1;
			if(VN(x, y) == 0 && VW(x, y) == -1) VN(x, y) = 1;
			if(VS(x + 1, y + 1) == -1 && VE(x + 1, y + 1) == 0) VE(x + 1, y + 1) = 1;
			if(VS(x + 1, y + 1) == 0 && VE(x + 1, y + 1) == -1) VS(x + 1, y + 1) = 1;
		}
		if(VS(x + 1, y) == -1 && VW(x + 1, y) == -1) {
			if(VN(x, y) == -1 && VW(x, y) == 0) VW(x, y) = 1;
			if(VN(x, y) == 0 && VW(x, y) == -1) VN(x, y) = 1;
			if(VS(x + 1, y + 1) == -1 && VE(x + 1, y + 1) == 0) VE(x + 1, y + 1) = 1;
			if(VS(x + 1, y + 1) == 0 && VE(x + 1, y + 1) == -1) VS(x + 1, y + 1) = 1;
		}
		if(VS(x + 1, y + 1) == -1 && VE(x + 1, y + 1) == -1) {
			if(VN(x, y + 1) == -1 && VE(x, y + 1) == 0) VE(x, y + 1) = 1;
			if(VN(x, y + 1) == 0 && VE(x, y + 1) == -1) VN(x, y + 1) = 1;
			if(VS(x + 1, y) == -1 && VW(x + 1, y) == 0) VW(x + 1, y) = 1;
			if(VS(x + 1, y) == 0 && VW(x + 1, y) == -1) VS(x + 1, y) = 1;
		}
		// case 16
		if(VN(x, y) == 1 && VW(x, y) == -1 || VN(x, y) == -1 && VW(x, y) == 1) {
			if(VS(x + 1, y + 1) == -1 && VE(x + 1, y + 1) == 0) VE(x + 1, y + 1) = 1;
			if(VS(x + 1, y + 1) == 0 && VE(x + 1, y + 1) == -1) VS(x + 1, y + 1) = 1;
		}
		if(VN(x, y + 1) == 1 && VE(x, y + 1) == -1 || VN(x, y + 1) == -1 && VE(x, y + 1) == 1) {
			if(VS(x + 1, y) == -1 && VW(x + 1, y) == 0) VW(x + 1, y) = 1;
			if(VS(x + 1, y) == 0 && VW(x + 1, y) == -1) VS(x + 1, y) = 1;
		}
		if(VS(x + 1, y) == 1 && VW(x + 1, y) == -1 || VS(x + 1, y) == -1 && VW(x + 1, y) == 1) {
			if(VN(x, y + 1) == -1 && VE(x, y + 1) == 0) VE(x, y + 1) = 1;
			if(VN(x, y + 1) == 0 && VE(x, y + 1) == -1) VN(x, y + 1) = 1;
		}
		if(VS(x + 1, y + 1) == 1 && VE(x + 1, y + 1) == -1 || VS(x + 1, y + 1) == -1 && VE(x + 1, y + 1) == 1) {
			if(VN(x, y) == -1 && VW(x, y) == 0) VW(x, y) = 1;
			if(VN(x, y) == 0 && VW(x, y) == -1) VN(x, y) = 1;
		}
	}

	// Core - solve
	void solve()
	{
		if(mark == 0) return;
		rule0();
		do {
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= m; j++) {
					rule2(i, j);
					rule3(i, j);					
				}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					rule1(i, j);
					rule4(i, j);
					rule5(i, j);
				}
		} while(mark > 0);
	}

	// showans
	void show(ostream& os)
	{
		os << "##";
		for (int j = 0; j < m; j++)
			os << "####";
		os << "###" << endl;
		os << "# ";
		for (int j = 0; j < m; j++)
			os << "    ";
		os << "  #" << endl;
		for (int i = 0; i < n; i++) {
			os << "# ";
			for (int j = 0; j < m; j++) {
				if(VN(i, j) == 1 && VS(i, j) == 1 && VW(i, j) == -1 && VE(i, j) == -1) os << "|";
				else if(VN(i, j) == -1 && VS(i, j) == -1 && VW(i, j) == 1 && VE(i, j) == 1) os << "-";
				else if(VN(i, j) == -1 && VS(i, j) == -1 && VW(i, j) == -1 && VE(i, j) == -1) os << " ";
				else os << "+";
				if(CN(i, j) == 1) os << "---";
				else os << "   ";
			}
			if(VN(i, m) == 1 && VS(i, m) == 1 && VW(i, m) == -1 && VE(i, m) == -1) os << "|";
			else if(VN(i, m) == -1 && VS(i, m) == -1 && VW(i, m) == 1 && VE(i, m) == 1) os << "-";
			else if(VN(i, m) == -1 && VS(i, m) == -1 && VW(i, m) == -1 && VE(i, m) == -1) os << " ";
			else os << "+";
			os << " #" << endl;
			os << "# ";
			for (int j = 0; j < m; j++) {
				if(CW(i, j) == 1) os << "|";
				else os << " ";
				os << " " << mp[i][j] << " ";
			}
			if(CE(i, m - 1) == 1) os << "|";
			else os << " ";
			os << " #" << endl;
		}
		os << "# ";
		for (int j = 0; j < m; j++) {
			if(VN(n, j) == 1 && VS(n, j) == 1 && VW(n, j) == -1 && VE(n, j) == -1) os << "|";
			else if(VN(n, j) == -1 && VS(n, j) == -1 && VW(n, j) == 1 && VE(n, j) == 1) os << "-";
			else if(VN(n, j) == -1 && VS(n, j) == -1 && VW(n, j) == -1 && VE(n, j) == -1) os << " ";
			else os << "+";
			if(CS(n - 1, j) == 1) os << "---";
			else os << "   ";
		}
		if(VN(n, m) == 1 && VS(n, m) == 1 && VW(n, m) == -1 && VE(n, m) == -1) os << "|";
		else if(VN(n, m) == -1 && VS(n, m) == -1 && VW(n, m) == 1 && VE(n, m) == 1) os << "-";
		else if(VN(n, m) == -1 && VS(n, m) == -1 && VW(n, m) == -1 && VE(n, m) == -1) os << " ";
		else os << "+";
		os << " #" << endl;
		os << "# ";
		for (int j = 0; j < m; j++)
			os << "    ";
		os << "  #" << endl;
		os << "##";
		for (int j = 0; j < m; j++)
			os << "####";
		os << "###" << endl;
	}

public:

	Slink(const vector<vector<int> > &vvi)
	{
		illegalRef = -1;
		n = vvi.size();
		m = vvi[0].size();
		mark = n * m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				mk[i][j] = false;
				mp[i][j] = vvi[i][j];				
			}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				vr[i][j] = false;
				eg[i][j][0] = eg[i][j][1] = 0;
			}
	}

	inline friend ostream& operator<<(ostream& os, Slink& that)
	{
		if(that.mark != 0) that.solve();
		that.show(os);
		return os;
	}

};

int main(void)
{
	int n, m, ri = 0;
	while(cin >> n >> m && n + m > 0) {
		vector<vector<int> > arg(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int k;
				cin >> k;
				arg[i].push_back(k);
			}
		Slink slink(arg);
		cout << ++ri << endl << slink;
	}
	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806012 	3848 	Slink 	Accepted 	C++ 	0.008 	2011-05-23 17:12:57
/*
id => 1174266
pid => 3848
pname => Slink
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:46:44
*/
