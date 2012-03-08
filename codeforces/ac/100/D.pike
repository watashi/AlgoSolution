int main() {
	constant in = Stdio.stdin;
	int n = (int)in->gets();
	string a = in->gets();
	string b = in->gets();
	string c = String.common_prefix(({a, b}));
	write(sizeof(a) + sizeof(b) - 2 * sizeof(c) <= n ? "YES" : "NO");
	return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669397 	Sep 5, 2011 5:38:40 PM 	watashi 	100D - World of Mouth 	Pike 	Accepted 	2020 ms 	43300 KB 
