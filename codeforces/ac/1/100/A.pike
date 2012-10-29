int main() {
	int n, k, m;
	sscanf(Stdio.stdin->gets(), "%d%d%d", n, k, m);
	n = (n + m - 1) / m;
	write(n * n <= k ? "YES" : "NO");
	return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669382 	Sep 5, 2011 5:33:36 PM 	watashi 	100A - Carpeting the Room 	Pike 	Accepted 	160 ms 	6500 KB
